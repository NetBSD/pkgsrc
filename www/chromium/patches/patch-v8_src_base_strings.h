$NetBSD: patch-v8_src_base_strings.h,v 1.25 2026/09/02 13:13:40 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/base/strings.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ v8/src/base/strings.h
@@ -9,6 +9,8 @@
 #include "src/base/macros.h"
 #include "src/base/vector.h"
 
+#include <cstdarg>
+
 namespace v8 {
 namespace base {
 
