$NetBSD: patch-chrome_browser_web__applications_os__integration_os__integration__test__override.h,v 1.28 2026/10/02 11:43:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/os_integration/os_integration_test_override.h.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/web_applications/os_integration/os_integration_test_override.h
@@ -103,7 +103,7 @@ class OsIntegrationTestOverride
   virtual base::FilePath chrome_apps_folder() = 0;
   virtual void EnableOrDisablePathOnLogin(const base::FilePath& file_path,
                                           bool enable_on_login) = 0;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual base::Environment* environment() = 0;
 #endif
 
