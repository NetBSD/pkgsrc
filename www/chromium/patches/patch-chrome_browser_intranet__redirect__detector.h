$NetBSD: patch-chrome_browser_intranet__redirect__detector.h,v 1.31 2026/10/23 15:05:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/intranet_redirect_detector.h.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/intranet_redirect_detector.h
@@ -26,7 +26,7 @@ class SimpleURLLoader;
 class PrefRegistrySimple;
 
 #if !(BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-      BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID))
+      BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD))
 #error \
     "IntranetRedirectDetector should only be built on Desktop platforms " \
     "and Android."
