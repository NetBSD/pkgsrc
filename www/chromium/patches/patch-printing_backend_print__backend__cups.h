$NetBSD: patch-printing_backend_print__backend__cups.h,v 1.20 2026/08/09 06:31:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/backend/print_backend_cups.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ printing/backend/print_backend_cups.h
@@ -17,7 +17,7 @@
 #include "printing/mojom/print.mojom.h"
 #include "url/gurl.h"
 
-static_assert(BUILDFLAG(IS_LINUX));
+static_assert(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD));
 
 namespace printing {
 
