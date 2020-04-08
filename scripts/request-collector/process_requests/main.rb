#!/usr/bin/env ruby

require_relative "../common/format"
require_relative "../common/hash"
require_relative "../common/list"
require_relative "requests"

log_urls_path         = ARGV[0]
valid_log_urls_path   = ARGV[1]
invalid_log_urls_path = ARGV[2]
method_symbols_path   = ARGV[3]
url_symbols_path      = ARGV[4]

log_urls         = read_list log_urls_path
valid_log_urls   = read_list valid_log_urls_path
invalid_log_urls = read_list invalid_log_urls_path
method_symbols   = read_hash method_symbols_path
url_symbols      = read_hash url_symbols_path

log_urls -= valid_log_urls
log_urls -= invalid_log_urls

text = colorize_length log_urls.length
warn "-- processing #{text} log urls"

begin
  process_requests log_urls, valid_log_urls, invalid_log_urls, method_symbols, url_symbols
ensure
  # You can stop processing at any time and it will sync all results.

  write_list valid_log_urls_path,   valid_log_urls
  write_list invalid_log_urls_path, invalid_log_urls
  write_hash method_symbols_path,   method_symbols
  write_hash url_symbols_path,      url_symbols
end
