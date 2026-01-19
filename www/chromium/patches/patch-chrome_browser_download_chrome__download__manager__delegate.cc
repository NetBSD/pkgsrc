$NetBSD: patch-chrome_browser_download_chrome__download__manager__delegate.cc,v 1.14 2026/01/19 16:14:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/download/chrome_download_manager_delegate.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/download/chrome_download_manager_delegate.cc
@@ -2021,7 +2021,7 @@ void ChromeDownloadManagerDelegate::OnDo
 bool ChromeDownloadManagerDelegate::IsOpenInBrowserPreferredForFile(
     const base::FilePath& path) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (path.MatchesExtension(FILE_PATH_LITERAL(".pdf"))) {
     return !download_prefs_->ShouldOpenPdfInSystemReader();
   }
@@ -2157,7 +2157,7 @@ void ChromeDownloadManagerDelegate::Chec
     content::CheckDownloadAllowedCallback check_download_allowed_cb) {
   DCHECK_CURRENTLY_ON(BrowserThread::UI);
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   // Don't download pdf if it is a file URL, as that might cause an infinite
   // download loop if Chrome is not the system pdf viewer.
   if (url.SchemeIsFile() && download_prefs_->ShouldOpenPdfInSystemReader()) {
@@ -2235,7 +2235,7 @@ void ChromeDownloadManagerDelegate::Chec
   DCHECK(download_item->IsSavePackageDownload());
 
 #if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-     BUILDFLAG(IS_MAC)) &&                                                 \
+     BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)) &&                                                 \
     BUILDFLAG(SAFE_BROWSING_AVAILABLE)
   std::optional<enterprise_connectors::AnalysisSettings> settings =
       safe_browsing::ShouldUploadBinaryForDeepScanning(download_item);
