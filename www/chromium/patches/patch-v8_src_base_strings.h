$NetBSD: patch-v8_src_base_strings.h,v 1.33 2026/11/19 19:46:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/base/strings.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ v8/src/base/strings.h
@@ -10,6 +10,8 @@
 #include "src/base/base-export.h"
 #include "src/base/macros.h"
 
+#include <cstdarg>
+
 namespace v8 {
 namespace base {
 
