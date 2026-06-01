$NetBSD: patch-v8_src_base_strings.h,v 1.20 2026/06/01 10:09:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/base/strings.h.orig	2026-05-26 20:39:02.000000000 +0000
+++ v8/src/base/strings.h
@@ -8,6 +8,9 @@
 #include "src/base/base-export.h"
 #include "src/base/macros.h"
 #include "src/base/vector.h"
+#if defined(__NetBSD__)
+#include <stdarg.h>
+#endif
 
 namespace v8 {
 namespace base {
