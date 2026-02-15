$NetBSD: patch-chrome_browser_ui_web__applications_web__app__dialogs.h,v 1.15 2026/02/15 09:04:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/web_applications/web_app_dialogs.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/ui/web_applications/web_app_dialogs.h
@@ -25,7 +25,7 @@
 #include "ui/gfx/native_ui_types.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-              BUILDFLAG(IS_CHROMEOS));
+              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD));
 
 class GURL;
 class Profile;
