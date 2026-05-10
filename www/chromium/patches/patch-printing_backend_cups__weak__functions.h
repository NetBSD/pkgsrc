$NetBSD: patch-printing_backend_cups__weak__functions.h,v 1.15 2026/05/10 15:30:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/backend/cups_weak_functions.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ printing/backend/cups_weak_functions.h
@@ -6,7 +6,7 @@
 
 #include "build/build_config.h"
 
-static_assert(BUILDFLAG(IS_LINUX));
+static_assert(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD));
 
 // Function availability can be tested by checking whether its address is not
 // nullptr. Weak symbols remove the need for platform specific build flags and
