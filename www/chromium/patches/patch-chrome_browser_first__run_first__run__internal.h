$NetBSD: patch-chrome_browser_first__run_first__run__internal.h,v 1.14 2026/01/19 16:14:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/first_run/first_run_internal.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/first_run/first_run_internal.h
@@ -72,7 +72,7 @@ FirstRunState DetermineFirstRunState(boo
                                      bool force_first_run,
                                      bool no_first_run);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // For testing, forces the first run dialog to either be shown or not. If not
 // called, the decision to show the dialog or not will be made by Chrome based
 // on a number of factors (such as install type, whether it's a Chrome-branded
