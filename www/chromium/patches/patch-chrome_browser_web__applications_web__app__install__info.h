$NetBSD: patch-chrome_browser_web__applications_web__app__install__info.h,v 1.7 2025/09/12 16:02:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/web_app_install_info.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ chrome/browser/web_applications/web_app_install_info.h
@@ -38,7 +38,7 @@
 #include "url/gurl.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-              BUILDFLAG(IS_CHROMEOS));
+              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD));
 
 namespace web_app {
 
