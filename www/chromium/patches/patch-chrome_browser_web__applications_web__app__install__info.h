$NetBSD: patch-chrome_browser_web__applications_web__app__install__info.h,v 1.15 2026/02/15 09:04:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/web_app_install_info.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/web_applications/web_app_install_info.h
@@ -43,7 +43,7 @@
 #include "url/gurl.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-              BUILDFLAG(IS_CHROMEOS));
+              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD));
 
 namespace web_app {
 
