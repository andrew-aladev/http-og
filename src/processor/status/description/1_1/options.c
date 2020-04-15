// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#include "options.h"

const char* HOG_CONSTANTS[] = {
  // RFC 7231 - 6.2.1 100 Continue.
  "Continue",

  // RFC 7231 - 6.2.2 101 Switching Protocols.
  "Switching Protocols",

  // RFC 7231 - 6.3.1 200 OK.
  "OK",

  // RFC 7231 - 6.3.2 201 Created.
  "Created",

  // RFC 7231 - 6.3.3 202 Accepted.
  "Accepted",

  // RFC 7231 - 6.3.4 203 Non-Authoritative Information.
  "Non-Authoritative Information",

  // RFC 7231 - 6.3.5 204 No Content.
  "No Content",

  // RFC 7231 - 6.3.6 205 Reset Content.
  "Reset Content",

  // RFC 7233 - 4.1 206 Partial Content.
  "Partial Content",

  // RFC 7231 - 6.4.1 300 Multiple Choices.
  "Multiple Choices",

  // RFC 7231 - 6.4.2 301 Moved Permanently.
  "Moved Permanently",

  // RFC 7231 - 6.4.3 302 Found.
  "Found",

  // RFC 7231 - 6.4.4 303 See Other.
  "See Other",

  // RFC 7232 - 4.1 304 Not Modified.
  "Not Modified",

  // RFC 7231 - 6.4.5 305 Use Proxy.
  "Use Proxy",

  // RFC 7231 - 6.4.6 306 (Unused).
  "(Unused)",

  // RFC 7231 - 6.4.7 307 Temporary Redirect.
  "Temporary Redirect",

  // RFC 7238 - 3 308 Permanent Redirect.
  "Permanent Redirect",

  // RFC 7231 - 6.5.1 400 Bad Request.
  "Bad Request",

  // RFC 7235 - 3.1 401 Unauthorized.
  "Unauthorized",

  // RFC 7231 - 6.5.2 402 Payment Required.
  "Payment Required",

  // RFC 7231 - 6.5.3 403 Forbidden.
  "Forbidden",

  // RFC 7231 - 6.5.4 404 Not Found.
  "Not Found",

  // RFC 7231 - 6.5.5 405 Method Not Allowed.
  "Method Not Allowed",

  // RFC 7231 - 6.5.6 406 Not Acceptable.
  "Not Acceptable",

  // RFC 7235 - 3.2 407 Proxy Authentication Required.
  "Proxy Authentication Required",

  // RFC 7231 - 6.5.7 408 Request Timeout.
  "Request Timeout",

  // RFC 7231 - 6.5.8 409 Conflict.
  "Conflict",

  // RFC 7231 - 6.5.9 410 Gone.
  "Gone",

  // RFC 7231 - 6.5.10 411 Length Required.
  "Length Required",

  // RFC 7232 - 4.2 412 Precondition Failed.
  "Precondition Failed",

  // RFC 7231 - 6.5.11 413 Payload Too Large.
  "Payload Too Large",

  // RFC 7231 - 6.5.12 414 URI Too Long.
  "URI Too Long",

  // RFC 7231 - 6.5.13 415 Unsupported Media Type.
  "Unsupported Media Type",

  // RFC 7233 - 4.4 416 Range Not Satisfiable.
  "Range Not Satisfiable",

  // RFC 7231 - 6.5.14 417 Expectation Failed.
  "Expectation Failed",

  // RFC 7231 - 6.5.15 426 Upgrade Required.
  "Upgrade Required",

  // RFC 7231 - 6.6.1 500 Internal Server Error.
  "Internal Server Error",

  // RFC 7231 - 6.6.2 501 Not Implemented.
  "Not Implemented",

  // RFC 7231 - 6.6.3 502 Bad Gateway.
  "Bad Gateway",

  // RFC 7231 - 6.6.4 503 Service Unavailable.
  "Service Unavailable",

  // RFC 7231 - 6.6.5 504 Gateway Timeout.
  "Gateway Timeout",

  // RFC 7231 - 6.6.6 505 HTTP Version Not Supported.
  "HTTP Version Not Supported"};

const size_t HOG_CONSTANTS_LENGTH = sizeof(HOG_CONSTANTS) / sizeof(HOG_CONSTANTS[0]);
