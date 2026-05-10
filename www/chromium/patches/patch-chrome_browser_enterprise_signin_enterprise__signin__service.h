$NetBSD: patch-chrome_browser_enterprise_signin_enterprise__signin__service.h,v 1.19 2026/05/10 15:29:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/signin/enterprise_signin_service.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/enterprise/signin/enterprise_signin_service.h
@@ -9,7 +9,7 @@
 
 #include "build/build_config.h"
 
-#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN))
+#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
 #error EnterpriseSigninService should only be built on desktop platforms.
 #endif  // !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN))
 
