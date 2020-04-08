require_relative "list"

SEPARATOR = " ".freeze

def read_hash(file_path)
  list = read_list file_path

  list.each_with_object({}) do |item, hash|
    values = item.split(SEPARATOR).map(&:strip).reject(&:empty?)
    key    = values[0]
    value  = values[1]

    hash[key] = value
  end
end

def write_hash(file_path, hash)
  list = hash
    .map do |key, value|
      key + SEPARATOR + value
    end
    .sort

  write_list file_path, list

  nil
end
