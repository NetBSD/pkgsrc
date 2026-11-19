$NetBSD: patch-printing_backend_print__backend__cups__ipp.cc,v 1.29 2026/11/19 19:46:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/backend/print_backend_cups_ipp.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ printing/backend/print_backend_cups_ipp.cc
@@ -20,7 +20,7 @@
 #include "printing/mojom/print.mojom.h"
 #include "printing/units.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/backend/cups_weak_functions.h"
 #endif
 
