// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#include "options.h"

// HTTP Method Registry https://www.iana.org/assignments/http-methods/http-methods.xml.

const char* HOG_CONSTANTS[] = {
  // RFC 7231 - 4.3.1 GET.
  "GET",

  // RFC 7231 - 4.3.2 HEAD.
  "HEAD",

  // RFC 7231 - 4.3.3 POST.
  "POST",

  // RFC 7231 - 4.3.4 PUT.
  "PUT",

  // RFC 7231 - 4.3.5 DELETE.
  "DELETE",

  // RFC 7231 - 4.3.6 CONNECT.
  "CONNECT",

  // RFC 7231 - 4.3.7 OPTIONS.
  "OPTIONS",

  // RFC 7231 - 4.3.8 TRACE.
  "TRACE",

  // RFC 2068 - 19.6.1.1 PATCH.
  "PATCH",

  // RFC 2068 - 19.6.1.2 LINK.
  "LINK",

  // RFC 2068 - 19.6.1.3 UNLINK.
  "UNLINK",

  // RFC 4918 - 9.1 PROPFIND Method.
  "PROPFIND",

  // RFC 4918 - 9.2 PROPPATCH Method.
  "PROPPATCH",

  // RFC 4918 - 9.3 MKCOL Method.
  "MKCOL",

  // RFC 4918 - 9.8 COPY Method.
  "COPY",

  // RFC 4918 - 9.9 MOVE Method.
  "MOVE",

  // RFC 4918 - 9.10 LOCK Method.
  "LOCK",

  // RFC 4918 - 9.11 UNLOCK Method.
  "UNLOCK",

  // RFC 5842 - 4 BIND Method.
  "BIND",

  // RFC 5842 - 5 UNBIND Method.
  "UNBIND",

  // RFC 5842 - 6 REBIND Method.
  "REBIND",

  // RFC 3744 - 8.1 ACL.
  "ACL",

  // RFC 3744 - 9.1 REPORT Method.
  "REPORT",

  // RFC 5323 - 2 The SEARCH Method.
  "SEARCH",

  // RFC 3253 - 3.5 VERSION-CONTROL Method.
  "VERSION-CONTROL",

  // RFC 3253 - 4.3 CHECKOUT Method (applied to a version-controlled resource).
  "CHECKOUT",

  // RFC 3253 - 4.4 CHECKIN Method (applied to a version-controlled resource).
  "CHECKIN",

  // RFC 3253 - 4.5 UNCHECKOUT Method.
  "UNCHECKOUT",

  // RFC 3253 - 6.3 MKWORKSPACE Method.
  "MKWORKSPACE",

  // RFC 3253 - 7.1 UPDATE Method.
  "UPDATE",

  // RFC 3253 - 8.2 LABEL Method.
  "LABEL",

  // RFC 3253 - 11.2 MERGE Method.
  "MERGE",

  // RFC 3253 - 12.6 BASELINE-CONTROL Method.
  "BASELINE-CONTROL",

  // RFC 3253 - 13.5 MKACTIVITY Method.
  "MKACTIVITY",

  // RFC 4437 - 6 MKREDIRECTREF Method.
  "MKREDIRECTREF",

  // RFC 4437 - 7 UPDATEREDIRECTREF Method.
  "UPDATEREDIRECTREF",

  // RFC 3648 - 7 Changing a Collection Ordering: ORDERPATCH method.
  "ORDERPATCH",

  // RFC 4791 - 5.3.1 MKCALENDAR Method.
  "MKCALENDAR",

  // RFC 7540 - 11.6 PRI Method Registration.
  "PRI"};

const size_t HOG_CONSTANTS_LENGTH = sizeof(HOG_CONSTANTS) / sizeof(HOG_CONSTANTS[0]);
