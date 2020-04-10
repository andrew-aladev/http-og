#!/usr/bin/env ruby

require "set"

require_relative "../common/format"
require_relative "../common/list"
require_relative "requests"

log_urls_path         = ARGV[0]
valid_log_urls_path   = ARGV[1]
invalid_log_urls_path = ARGV[2]
request_methods_path  = ARGV[3]
request_uris_path     = ARGV[4]

log_urls         = read_list log_urls_path
valid_log_urls   = read_list valid_log_urls_path
invalid_log_urls = read_list invalid_log_urls_path
request_methods  = read_list(request_methods_path).to_set
request_uris     = read_list(request_uris_path).to_set

log_urls -= valid_log_urls
log_urls -= invalid_log_urls

text = colorize_length log_urls.length
warn "-- processing #{text} log urls"

begin
  process_requests log_urls, valid_log_urls, invalid_log_urls, request_methods, request_uris
ensure
  # You can stop processing at any time and it will sync all results.

  write_list valid_log_urls_path,   valid_log_urls.sort.uniq
  write_list invalid_log_urls_path, invalid_log_urls.sort.uniq
  write_list request_methods_path,  request_methods.to_a.sort.uniq
  write_list request_uris_path,     request_uris.to_a.sort.uniq
end
