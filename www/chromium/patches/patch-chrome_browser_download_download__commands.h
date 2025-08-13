$NetBSD: patch-chrome_browser_download_download__commands.h,v 1.5 2025/08/13 07:44:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/download/download_commands.h.orig	2025-07-29 22:51:44.000000000 +0000
+++ chrome/browser/download/download_commands.h
@@ -66,7 +66,7 @@ class DownloadCommands {
   void ExecuteCommand(Command command);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   bool IsDownloadPdf() const;
   bool CanOpenPdfInSystemViewer() const;
   Browser* GetBrowser() const;
