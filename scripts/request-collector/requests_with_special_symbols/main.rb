#!/usr/bin/env ruby

require "pp"

require_relative "../common/requests"

requests = read_requests ARGV[0]

special_symbols_data = requests.each_with_object({}) do |request, data|
  request[:request_uri].chars.each do |char|
    next if REQUEST_URI_REGULAR_CHARS.include? char

    if data.key? char
      data[char] << request
    else
      data[char] = [request]
    end
  end
end

pp special_symbols_data.keys
pp special_symbols_data
