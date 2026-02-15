$NetBSD: patch-v8_src_base_strings.h,v 1.15 2026/02/15 09:04:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/base/strings.h.orig	2026-02-03 22:07:10.000000000 +0000
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
