$NetBSD: patch-components_web__package_web__bundle__parser.cc,v 1.1 2026/10/23 15:05:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/web_package/web_bundle_parser.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ components/web_package/web_bundle_parser.cc
@@ -2,6 +2,8 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#if 0
+// XXX crubit
 #include "components/web_package/web_bundle_parser.h"
 
 #include <algorithm>
@@ -544,3 +546,4 @@ bool WebBundleParser::CheckIfClosed() {
 }
 
 }  // namespace web_package
+#endif 
