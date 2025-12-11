$NetBSD: patch-chrome_browser_web__applications_web__app__install__info.h,v 1.11 2025/12/11 09:13:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/web_app_install_info.h.orig	2025-11-19 21:40:05.000000000 +0000
+++ chrome/browser/web_applications/web_app_install_info.h
@@ -41,7 +41,7 @@
 #include "url/gurl.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-              BUILDFLAG(IS_CHROMEOS));
+              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD));
 
 namespace web_app {
 
