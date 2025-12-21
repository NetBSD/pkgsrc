$NetBSD: patch-src_3rdparty_chromium_base_posix_file__descriptor__shuffle.h,v 1.1 2025/12/21 09:38:14 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/posix/file_descriptor_shuffle.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/base/posix/file_descriptor_shuffle.h
@@ -26,6 +26,8 @@
 #include "base/base_export.h"
 #include "base/compiler_specific.h"
 
+#undef close
+
 namespace base {
 
 // A Delegate which performs the actions required to perform an injective
