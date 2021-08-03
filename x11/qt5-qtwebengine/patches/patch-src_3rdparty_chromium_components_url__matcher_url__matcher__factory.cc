$NetBSD: patch-src_3rdparty_chromium_components_url__matcher_url__matcher__factory.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/url_matcher/url_matcher_factory.cc.orig	2020-07-08 21:40:41.000000000 +0000
+++ src/3rdparty/chromium/components/url_matcher/url_matcher_factory.cc
@@ -16,7 +16,7 @@
 #include "base/values.h"
 #include "components/url_matcher/url_matcher_constants.h"
 #include "components/url_matcher/url_matcher_helpers.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 
 namespace url_matcher {
 
