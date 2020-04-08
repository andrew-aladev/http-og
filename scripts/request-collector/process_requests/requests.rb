require "colorize"
require "filesize"
require "uri"

require_relative "../common/format"
require_relative "../common/query"
require_relative "./archive"

TEMP_DIRECTORY = File.join(File.dirname(__FILE__), "..", "..", "..", "tmp").freeze
LOG_PATH       = File.join(TEMP_DIRECTORY, "log").freeze

# ArchiveReader.read_lines(file_path) do |line|
# end

def download_log(url)
  begin
    uri    = URI url
    scheme = uri.scheme

    case scheme
    when "ftp"
      download_file_from_ftp uri, LOG_PATH
    when "http", "https"
      download_http_file uri, LOG_PATH
    else
      raise StandardError, "unknown uri scheme: #{scheme}"
    end

  rescue StandardError => error
    warn error
    return nil
  end

  LOG_PATH
end

def process_requests(log_urls, valid_log_urls, invalid_log_urls, method_symbols, url_symbols)
  logs_size = 0

  invalid_log_urls_length = 0
  valid_log_urls_length   = 0
  method_symbols_length   = 0
  url_symbols_length      = 0

  log_urls
    .shuffle
    .each_with_index do |log_url, index|
      percent = format_percent index, log_urls.length
      warn "- #{percent}% processing log, url: #{log_url}"

      file_path = download_log log_url
      next if file_path.nil?

      begin
        size = File.size file_path
        warn "downloaded log, size: #{Filesize.new(size).pretty}"

        ;

        logs_size += size

      ensure
        File.delete file_path
      end
    end

  logs_size_text = Filesize.new(logs_size).pretty

  invalid_log_urls_text = colorize_length invalid_log_urls_length
  valid_log_urls_text   = colorize_length valid_log_urls_length
  method_symbols_text   = colorize_length method_symbols_length
  url_symbols_text      = colorize_length url_symbols_length

  warn(
    "-- processed #{logs_size_text} logs size, received " \
    "#{invalid_log_urls_text} invalid logs, " \
    "#{valid_log_urls_text} valid logs, " \
    "#{method_symbols_text} method symbols, " \
    "#{url_symbols_text} url symbols"
  )

  nil
end
