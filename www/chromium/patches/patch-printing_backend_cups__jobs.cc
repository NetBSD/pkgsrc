$NetBSD: patch-printing_backend_cups__jobs.cc,v 1.3 2025/09/12 16:02:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/backend/cups_jobs.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ printing/backend/cups_jobs.cc
@@ -31,7 +31,7 @@
 #include "printing/backend/cups_ipp_helper.h"
 #include "printing/printer_status.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/backend/cups_weak_functions.h"
 #endif
 
