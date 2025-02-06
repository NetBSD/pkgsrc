$NetBSD: patch-chrome_browser_download_download__commands.cc,v 1.1 2025/02/06 09:57:46 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/download/download_commands.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/download/download_commands.cc
@@ -26,7 +26,7 @@
 #include "ui/base/clipboard/scoped_clipboard_writer.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser.h"
 #include "chrome/browser/ui/browser_finder.h"
 #include "chrome/browser/ui/scoped_tabbed_browser_displayer.h"
@@ -166,7 +166,7 @@ void DownloadCommands::ExecuteCommand(Co
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 Browser* DownloadCommands::GetBrowser() const {
   if (!model_)
