$NetBSD: patch-chrome_browser_download_download__commands.cc,v 1.7 2025/09/12 16:02:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/download/download_commands.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ chrome/browser/download/download_commands.cc
@@ -27,7 +27,7 @@
 #include "ui/base/clipboard/scoped_clipboard_writer.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser.h"
 #include "chrome/browser/ui/browser_finder.h"
 #include "chrome/browser/ui/scoped_tabbed_browser_displayer.h"
@@ -177,7 +177,7 @@ void DownloadCommands::ExecuteCommand(Co
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 Browser* DownloadCommands::GetBrowser() const {
   if (!model_)
