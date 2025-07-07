$NetBSD: patch-chrome_browser_first__run_first__run__dialog.h,v 1.3 2025/07/07 09:23:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/first_run/first_run_dialog.h.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/first_run/first_run_dialog.h
@@ -9,7 +9,7 @@
 #include "build/build_config.h"
 
 // Hide this function on platforms where the dialog does not exist.
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 namespace first_run {
 
