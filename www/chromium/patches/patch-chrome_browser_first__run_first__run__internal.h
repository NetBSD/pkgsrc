$NetBSD: patch-chrome_browser_first__run_first__run__internal.h,v 1.25 2026/09/02 13:13:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/first_run/first_run_internal.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/first_run/first_run_internal.h
@@ -72,13 +72,13 @@ FirstRunState DetermineFirstRunState(boo
                                      bool force_first_run,
                                      bool no_first_run);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Shows the EULA dialog if required. Returns true if the EULA is accepted
 // or not required. Returns false if the EULA has not been accepted.
 bool ShowEulaDialog();
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // For testing, forces the first run dialog to either be shown or not. If not
 // called, the decision to show the dialog or not will be made by Chrome based
 // on a number of factors (such as install type, whether it's a Chrome-branded
