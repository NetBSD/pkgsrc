$NetBSD: patch-src_3rdparty_chromium_extensions_browser_api_web__request_form__data__parser.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/extensions/browser/api/web_request/form_data_parser.cc.orig	2020-07-08 21:40:43.000000000 +0000
+++ src/3rdparty/chromium/extensions/browser/api/web_request/form_data_parser.cc
@@ -16,7 +16,7 @@
 #include "base/values.h"
 #include "net/base/escape.h"
 #include "net/http/http_request_headers.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 
 using base::DictionaryValue;
 using base::ListValue;
