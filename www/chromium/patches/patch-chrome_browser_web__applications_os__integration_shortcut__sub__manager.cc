$NetBSD: patch-chrome_browser_web__applications_os__integration_shortcut__sub__manager.cc,v 1.6 2025/09/08 13:24:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/os_integration/shortcut_sub_manager.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/browser/web_applications/os_integration/shortcut_sub_manager.cc
@@ -198,7 +198,7 @@ void ShortcutSubManager::Execute(
     return;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   // Protocol handler update detection. Shortcuts need to be updated in this
   // case on Linux & Mac because the shortcut itself includes the protocol
   // handling metadata.
