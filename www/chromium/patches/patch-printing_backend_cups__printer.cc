$NetBSD: patch-printing_backend_cups__printer.cc,v 1.29 2026/11/19 19:46:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/backend/cups_printer.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ printing/backend/cups_printer.cc
@@ -24,7 +24,7 @@
 #include "printing/print_job_constants.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/backend/cups_weak_functions.h"
 #endif
 
