$NetBSD: patch-chrome_browser_web__applications_os__integration_web__app__file__handler__registration.h,v 1.30 2026/10/16 15:30:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/os_integration/web_app_file_handler_registration.h.orig	2026-10-14 21:09:54.000000000 +0000
+++ chrome/browser/web_applications/os_integration/web_app_file_handler_registration.h
@@ -40,7 +40,7 @@ void UnregisterFileHandlersWithOs(const 
                                   const base::FilePath& profile_path,
                                   ResultCallback callback);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Exposed for testing purposes. Register the set of
 // MIME-type-to-file-extensions mappings corresponding to |file_handlers|. File
 // I/O and callouts to the Linux shell are performed asynchronously.
