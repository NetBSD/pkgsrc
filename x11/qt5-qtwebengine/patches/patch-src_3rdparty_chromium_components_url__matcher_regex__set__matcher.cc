$NetBSD: patch-src_3rdparty_chromium_components_url__matcher_regex__set__matcher.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/url_matcher/regex_set_matcher.cc.orig	2020-07-08 21:40:41.000000000 +0000
+++ src/3rdparty/chromium/components/url_matcher/regex_set_matcher.cc
@@ -12,8 +12,8 @@
 #include "base/logging.h"
 #include "base/strings/string_util.h"
 #include "components/url_matcher/substring_set_matcher.h"
-#include "third_party/re2/src/re2/filtered_re2.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/filtered_re2.h>
+#include <re2/re2.h>
 
 namespace url_matcher {
 
