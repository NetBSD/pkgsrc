$NetBSD: patch-chrome_browser_download_download__prefs.h,v 1.13 2025/12/23 13:22:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/download/download_prefs.h.orig	2025-12-17 23:05:18.000000000 +0000
+++ chrome/browser/download/download_prefs.h
@@ -107,7 +107,7 @@ class DownloadPrefs {
   void DisableAutoOpenByUserBasedOnExtension(const base::FilePath& file_name);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   // Store the user preference to disk. If |should_open| is true, also disable
   // the built-in PDF plugin. If |should_open| is false, enable the PDF plugin.
   void SetShouldOpenPdfInSystemReader(bool should_open);
@@ -171,7 +171,7 @@ class DownloadPrefs {
   std::unique_ptr<policy::URLBlocklist> auto_open_allowed_by_urls_;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   bool should_open_pdf_in_system_reader_;
 #endif
 
