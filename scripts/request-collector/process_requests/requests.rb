require "colorize"
require "filesize"
require "uri"

require_relative "../common/format"
require_relative "../common/query"
require_relative "./archive"

TEMP_DIRECTORY = File.join(File.dirname(__FILE__), "..", "..", "..", "tmp").freeze
LOG_PATH       = File.join(TEMP_DIRECTORY, "log").freeze

# Request: "GET /a/b HTTP/1.0" 200 .
REQUEST_REGEXP = Regexp.new(
  "
    ['\"]
      (
        [^'\"[:space:]]+
      )
      [ ]

      (
        [^[:space:]]+
      )
      [ ]

      HTTP/
      (?:
          1\.0
        |
          1\.1
      )
    ['\"]
    [ ]

    [123]
    [0-9]{2}
    [ ]
  ",
  Regexp::MULTILINE | Regexp::EXTENDED
)
.freeze

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

def get_request_uris_symbols(request_uris)
  request_uris.each_with_object({}) do |request_uri, request_uris_symbols|
    request_uri.each_char { |char| request_uris_symbols[char] = true }
  end
end

def process_archive(file_path, request_methods, request_uris, request_symbols_hash)
  requests_length        = 0
  request_methods_length = 0
  request_uris_length    = 0

  begin
    ArchiveReader.read_lines(file_path) do |line|
      line
        .scan(REQUEST_REGEXP)
        .compact
        .each do |match|
          next if match.length != 2

          request_method = match[0]
          request_uri    = match[1]

          unless request_method.ascii_only?
            warn "request method: #{request_method} is not ascii only"
            next
          end

          unless request_uri.ascii_only?
            warn "request uri: #{request_uri} is not ascii only"
            next
          end

          unless request_methods.include? request_method
            request_methods.add request_method
            request_methods_length += 1
          end

          is_new_request_uri = request_uri.chars.any? { |char| request_symbols_hash[char].nil? }
          if is_new_request_uri
            request_uri.each_char { |char| request_symbols_hash[char] = true }
            request_uris.add request_uri
            request_uris_length += 1
          end

          requests_length += 1
        end
    end

  rescue Archive::Error => error
    warn error
  end

  result = requests_length != 0

  if result
    requests_text        = colorize_length requests_length
    request_methods_text = colorize_length request_methods_length
    request_uris_text    = colorize_length request_uris_length

    warn(
      "log is valid, received " \
      "#{requests_text} requests, " \
      "#{request_methods_text} new request methods, " \
      "#{request_uris_text} new request uris"
    )
  else
    warn "log is invalid"
  end

  [result, request_methods_length, request_uris_length]
end

def process_requests(log_urls, valid_log_urls, invalid_log_urls, request_methods, request_uris)
  request_uris_symbols = get_request_uris_symbols request_uris

  logs_size = 0

  invalid_log_urls_length = 0
  valid_log_urls_length   = 0
  request_methods_length  = 0
  request_uris_length     = 0

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

        result, new_request_methods_length, new_request_uris_length = process_archive file_path, request_methods, request_uris, request_uris_symbols

        if result
          valid_log_urls_length += 1
          valid_log_urls << log_url
        else
          invalid_log_urls_length += 1
          invalid_log_urls << log_url
        end

        request_methods_length += new_request_methods_length
        request_uris_length    += new_request_uris_length
        logs_size              += size

      ensure
        File.delete file_path
      end
    end

  logs_size_text = Filesize.new(logs_size).pretty

  invalid_log_urls_text = colorize_length invalid_log_urls_length
  valid_log_urls_text   = colorize_length valid_log_urls_length
  request_methods_text  = colorize_length request_methods_length
  request_uris_text     = colorize_length request_uris_length

  warn(
    "-- processed #{logs_size_text} logs size, received " \
    "#{invalid_log_urls_text} invalid logs, " \
    "#{valid_log_urls_text} valid logs, " \
    "#{request_methods_text} request methods, " \
    "#{request_uris_text} request uris"
  )

  nil
end
