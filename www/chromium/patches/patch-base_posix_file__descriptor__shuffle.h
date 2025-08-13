$NetBSD: patch-base_posix_file__descriptor__shuffle.h,v 1.5 2025/08/13 07:44:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/posix/file_descriptor_shuffle.h.orig	2025-07-29 22:51:44.000000000 +0000
+++ base/posix/file_descriptor_shuffle.h
@@ -26,6 +26,8 @@
 #include "base/base_export.h"
 #include "base/compiler_specific.h"
 
+#undef close
+
 namespace base {
 
 // A Delegate which performs the actions required to perform an injective
