$NetBSD: patch-chrome_browser_download_download__file__picker.cc,v 1.8 2025/10/16 19:43:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/download/download_file_picker.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ chrome/browser/download/download_file_picker.cc
@@ -18,7 +18,7 @@
 #include "content/public/browser/web_contents.h"
 #include "ui/shell_dialogs/selected_file_info.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_list.h"
 #include "chrome/browser/ui/browser_window.h"
 #include "ui/aura/window.h"
@@ -83,7 +83,7 @@ DownloadFilePicker::DownloadFilePicker(d
   // dialog in Linux (See SelectFileImpl() in select_file_dialog_linux_gtk.cc).
   // and windows.Here we make owning_window host to browser current active
   // window if it is null. https://crbug.com/1301898
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (!owning_window || !owning_window->GetHost()) {
     owning_window = BrowserList::GetInstance()
                         ->GetLastActive()
