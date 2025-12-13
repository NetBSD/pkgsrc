$NetBSD: patch-components_feed_core_v2_test_proto__printer.cc,v 1.12 2025/12/13 14:53:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/feed/core/v2/test/proto_printer.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ components/feed/core/v2/test/proto_printer.cc
@@ -159,8 +159,8 @@ class TextProtoPrinter {
   }
   TextProtoPrinter& operator<<(const feedwire::Version& v) {
     BeginMessage();
-    PRINT_FIELD(major);
-    PRINT_FIELD(minor);
+    PRINT_FIELD(gmajor);
+    PRINT_FIELD(gminor);
     PRINT_FIELD(build);
     PRINT_FIELD(revision);
     PRINT_FIELD(architecture);
