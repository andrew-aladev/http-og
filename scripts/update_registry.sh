#!/bin/bash -l
set -e

DIR=$(dirname "${BASH_SOURCE[0]}")
cd "$DIR"

cd "../registry"

wget "https://www.iana.org/assignments/http-methods/http-methods.xml" \
  -O "http-methods.xml"

wget "https://www.iana.org/assignments/http-status-codes/http-status-codes.xml" \
  -O "http-status-codes.xml"
