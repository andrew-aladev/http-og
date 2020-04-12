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

puts "- special symbols:"
pp special_symbols_data.keys
puts

puts "- special symbols requests count:"
count = special_symbols_data.each_with_object({}) do |value, data|
  data[value[0]] = value[1].length
  data
end
pp count
puts

puts "- special symbols log urls count:"
count = special_symbols_data.each_with_object({}) do |value, data|
  data[value[0]] = value[1]
    .map { |request| request[:log_url] }
    .sort
    .uniq
    .length
  data
end
pp count
puts

puts "- full data:"
pp special_symbols_data
