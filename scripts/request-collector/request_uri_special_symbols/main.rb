#!/usr/bin/env ruby

require_relative "../common/list"

REGULAR_CHAR_RANGES = [
  "0".."9",
  "a".."z",
  "A".."Z"
]
.freeze

request_uris = read_list ARGV[0]

special_symbols = request_uris.flat_map do |uri|
  uri.chars.reject do |char|
    REGULAR_CHAR_RANGES.any? { |range| range.include? char }
  end
end

puts special_symbols.sort.uniq
