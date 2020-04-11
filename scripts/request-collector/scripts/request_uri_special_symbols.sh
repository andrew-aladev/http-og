#!/bin/bash
set -e

DIR=$(dirname "${BASH_SOURCE[0]}")
cd "$DIR"

cd ".."

./request_uri_special_symbols/main.rb "data/request_uris_with_unique_symbols.xz"
