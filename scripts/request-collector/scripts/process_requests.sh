#!/bin/bash
set -e

DIR=$(dirname "${BASH_SOURCE[0]}")
cd "$DIR"

cd ".."

../mount_tmp.sh

./process_requests/main.rb \
  "data/log_urls.xz" \
  "data/valid_log_urls.xz" \
  "data/invalid_log_urls.xz" \
  "data/requests_with_special_symbols.xz"
