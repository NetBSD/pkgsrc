$NetBSD: patch-v8_src_base_strings.h,v 1.31 2026/10/23 15:05:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/base/strings.h.orig	2026-10-19 20:07:21.000000000 +0000
+++ v8/src/base/strings.h
@@ -9,6 +9,8 @@
 #include "src/base/macros.h"
 #include "src/base/vector.h"
 
+#include <cstdarg>
+
 namespace v8 {
 namespace base {
 
