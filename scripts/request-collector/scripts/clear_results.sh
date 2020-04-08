#!/bin/bash
set -e

DIR=$(dirname "${BASH_SOURCE[0]}")
cd "$DIR"

cd ".."

truncate --size=0 \
  "data/valid_log_urls.xz" \
  "data/invalid_log_urls.xz" \
  "data/method_symbols.xz" \
  "data/url_symbols.xz"
