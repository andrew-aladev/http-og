require "set"
require_relative "list"

def read_set(file_path)
  read_list(file_path).to_set
end

def write_set(file_path, list)
  write_list file_path, list.to_a
end
