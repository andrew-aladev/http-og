// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#include "options.h"

const char* HOG_CONSTANTS[] = {
  // RFC 7231 - 6.2.1 100 Continue.
  "100",

  // RFC 7231 - 6.2.2 101 Switching Protocols.
  "101",

  // RFC 7231 - 6.3.1 200 OK.
  "200",

  // RFC 7231 - 6.3.2 201 Created.
  "201",

  // RFC 7231 - 6.3.3 202 Accepted.
  "202",

  // RFC 7231 - 6.3.4 203 Non-Authoritative Information.
  "203",

  // RFC 7231 - 6.3.5 204 No Content.
  "204",

  // RFC 7231 - 6.3.6 205 Reset Content.
  "205",

  // RFC 7233 - 4.1 206 Partial Content.
  "206",

  // RFC 7231 - 6.4.1 300 Multiple Choices.
  "300",

  // RFC 7231 - 6.4.2 301 Moved Permanently.
  "301",

  // RFC 7231 - 6.4.3 302 Found.
  "302",

  // RFC 7231 - 6.4.4 303 See Other.
  "303",

  // RFC 7232 - 4.1 304 Not Modified.
  "304",

  // RFC 7231 - 6.4.5 305 Use Proxy.
  "305",

  // RFC 7231 - 6.4.6 306 (Unused).
  "306",

  // RFC 7231 - 6.4.7 307 Temporary Redirect.
  "307",

  // RFC 7238 - 3 308 Permanent Redirect.
  "308",

  // RFC 7231 - 6.5.1 400 Bad Request.
  "400",

  // RFC 7235 - 3.1 401 Unauthorized.
  "401",

  // RFC 7231 - 6.5.2 402 Payment Required.
  "402",

  // RFC 7231 - 6.5.3 403 Forbidden.
  "403",

  // RFC 7231 - 6.5.4 404 Not Found.
  "404",

  // RFC 7231 - 6.5.5 405 Method Not Allowed.
  "405",

  // RFC 7231 - 6.5.6 406 Not Acceptable.
  "406",

  // RFC 7235 - 3.2 407 Proxy Authentication Required.
  "407",

  // RFC 7231 - 6.5.7 408 Request Timeout.
  "408",

  // RFC 7231 - 6.5.8 409 Conflict.
  "409",

  // RFC 7231 - 6.5.9 410 Gone.
  "410",

  // RFC 7231 - 6.5.10 411 Length Required.
  "411",

  // RFC 7232 - 4.2 412 Precondition Failed.
  "412",

  // RFC 7231 - 6.5.11 413 Payload Too Large.
  "413",

  // RFC 7231 - 6.5.12 414 URI Too Long.
  "414",

  // RFC 7231 - 6.5.13 415 Unsupported Media Type.
  "415",

  // RFC 7233 - 4.4 416 Range Not Satisfiable.
  "416",

  // RFC 7231 - 6.5.14 417 Expectation Failed.
  "417",

  // RFC 7231 - 6.5.15 426 Upgrade Required.
  "426",

  // RFC 7231 - 6.6.1 500 Internal Server Error.
  "500",

  // RFC 7231 - 6.6.2 501 Not Implemented.
  "501",

  // RFC 7231 - 6.6.3 502 Bad Gateway.
  "502",

  // RFC 7231 - 6.6.4 503 Service Unavailable.
  "503",

  // RFC 7231 - 6.6.5 504 Gateway Timeout.
  "504",

  // RFC 7231 - 6.6.6 505 HTTP Version Not Supported.
  "505"};

const size_t HOG_CONSTANTS_LENGTH = sizeof(HOG_CONSTANTS) / sizeof(HOG_CONSTANTS[0]);
