$NetBSD: patch-printing_backend_cups__jobs.cc,v 1.11 2026/02/15 09:04:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/backend/cups_jobs.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ printing/backend/cups_jobs.cc
@@ -26,7 +26,7 @@
 #include "printing/backend/cups_ipp_helper.h"
 #include "printing/printer_status.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/backend/cups_weak_functions.h"
 #endif
 
