#!/bin/bash
set -e

DIR=$(dirname "${BASH_SOURCE[0]}")
cd "$DIR"

cd ".."

./process_requests/main.rb \
  "data/log_urls.xz" \
  "data/valid_log_urls.xz" \
  "data/invalid_log_urls.xz" \
  "data/request_methods.xz" \
  "data/request_uris_with_unique_symbols.xz"
