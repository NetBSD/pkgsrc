$NetBSD: patch-chrome_browser_shell__integration.h,v 1.2 2026/02/15 09:03:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/shell_integration.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/shell_integration.h
@@ -188,7 +188,7 @@ std::u16string GetAppShortcutsSubdirName
 #endif
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Returns the URL scheme for google-chrome:// URLs.
 // This varies based on channel, branding, and platform to ensure that
 // different installations do not collide. For example:
