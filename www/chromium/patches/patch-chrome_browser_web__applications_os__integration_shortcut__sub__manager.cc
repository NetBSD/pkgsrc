$NetBSD: patch-chrome_browser_web__applications_os__integration_shortcut__sub__manager.cc,v 1.16 2026/03/14 12:40:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/os_integration/shortcut_sub_manager.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ chrome/browser/web_applications/os_integration/shortcut_sub_manager.cc
@@ -197,7 +197,7 @@ void ShortcutSubManager::Execute(
     return;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   // Protocol handler update detection. Shortcuts need to be updated in this
   // case on Linux & Mac because the shortcut itself includes the protocol
   // handling metadata.
