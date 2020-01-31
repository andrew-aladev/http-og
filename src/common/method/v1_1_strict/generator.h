// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#if !defined(OGHTTP_METHOD_v1_1_STRICT_GENERATOR_H)
#define OGHTTP_METHOD_v1_1_STRICT_GENERATOR_H

// HTTP Method Registry https://www.iana.org/assignments/http-methods/http-methods.xml

const char * CONSTANTS[] = {
  // RFC 2616 - HTTP/1.1
  "OPTIONS",
  "GET",
  "HEAD",
  "POST",
  "PUT",
  "DELETE",
  "TRACE",
  "CONNECT",

  // RFC 2068 - HTTP/1.1
  "PATCH",
  "LINK",
  "UNLINK",

  // RFC 4918 - WebDAV
  "PROPFIND",
  "PROPPATCH",
  "MKCOL",
  "COPY",
  "MOVE",
  "LOCK",
  "UNLOCK",

  // RFC 5842 - Binding Extensions to WebDAV
  "BIND",
  "UNBIND",
  "REBIND",

  // RFC 3744 - WebDAV Access Control Protocol
  "ACL",
  "REPORT",

  // RFC 5323 - WebDAV SEARCH
  "SEARCH",

  // RFC 3253 - Versioning Extensions to WebDAV
  "VERSION-CONTROL",
  "CHECKOUT",
  "CHECKIN",
  "UNCHECKOUT",
  "MKWORKSPACE",
  "UPDATE",
  "LABEL",
  "MERGE",
  "BASELINE-CONTROL",
  "MKACTIVITY",

  // RFC 4437 - WebDAV Redirect Reference Resources
  "MKREDIRECTREF",
  "UPDATEREDIRECTREF",

  // RFC 3648 - WebDAV Ordered Collections Protocol
  "ORDERPATCH",

  // RFC 4791 - CalDAV
  "MKCALENDAR",

  // RFC 7540 - HTTP/2
  "PRI"
};

#endif // OGHTTP_METHOD_v1_1_STRICT_GENERATOR_H
