$NetBSD: patch-base_posix_can__lower__nice__to.cc,v 1.14 2026/01/19 16:14:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/posix/can_lower_nice_to.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/posix/can_lower_nice_to.cc
@@ -11,8 +11,12 @@
 
 #include "build/build_config.h"
 
+#if BUILDFLAG(IS_FREEBSD)
+#include <sys/param.h>
+#endif
+
 // Not defined on AIX by default.
-#if BUILDFLAG(IS_AIX)
+#if BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
 #if defined(RLIMIT_NICE)
 #error Assumption about OS_AIX is incorrect
 #endif
