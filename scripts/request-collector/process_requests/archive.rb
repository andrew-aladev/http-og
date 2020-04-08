require "ffi-libarchive"

class ArchiveReader < Archive::BaseArchive
  C      = Archive::C
  Error  = Archive::Error
  Header = Archive::Entry

  BLOCK_SIZE      = 1024
  BUFFER_SIZE     = C::DATA_BUFFER_SIZE
  LINE_TERMINATOR = "\n".freeze

  def initialize(file_path)
    super C.method(:archive_read_new), C.method(:archive_read_finish)

    if C.archive_read_support_compression_all(archive) != C::OK ||
       C.archive_read_support_format_all(archive) != C::OK ||
       C.archive_read_support_format_raw(archive) != C::OK ||
       C.archive_read_open_filename(archive, file_path, BLOCK_SIZE) != C::OK
      close
      raise Error, @archive
    end
  end

  def next_header
    header_ptr = FFI::MemoryPointer.new :pointer

    case C.archive_read_next_header archive, header_ptr
    when C::OK
      Header.from_pointer header_ptr.read_pointer
    when C::EOF
      @eof = true
      nil
    else
      raise Error, @archive
    end
  end

  def read(&_block)
    buffer = FFI::MemoryPointer.new BUFFER_SIZE

    until next_header.nil?
      loop do
        length = C.archive_read_data archive, buffer, BUFFER_SIZE

        break if length.zero?
        raise Error, @archive if length < 0

        yield buffer.get_bytes(0, length)
      end
    end
  end

  def self.read(file_path, &block)
    instance = new file_path

    begin
      instance.read(&block)
    ensure
      instance.close
    end
  end

  def self.read_lines(file_path, &_block)
    data = String.new :encoding => ::Encoding::BINARY

    read(file_path) do |bytes|
      data << bytes

      loop do
        index = data.index LINE_TERMINATOR
        break if index.nil?

        yield data.byteslice(0, index)

        next_index = index + 1
        data       = data.byteslice next_index, data.length - next_index
      end
    end

    yield data
  end
end
