$NetBSD: patch-chrome_browser_web__applications_os__integration_web__app__file__handler__registration.h,v 1.14 2026/01/19 16:14:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/os_integration/web_app_file_handler_registration.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/web_applications/os_integration/web_app_file_handler_registration.h
@@ -43,7 +43,7 @@ void UnregisterFileHandlersWithOs(const 
                                   const base::FilePath& profile_path,
                                   ResultCallback callback);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Exposed for testing purposes. Register the set of
 // MIME-type-to-file-extensions mappings corresponding to |file_handlers|. File
 // I/O and callouts to the Linux shell are performed asynchronously.
