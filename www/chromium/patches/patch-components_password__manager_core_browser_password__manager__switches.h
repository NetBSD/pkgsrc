$NetBSD: patch-components_password__manager_core_browser_password__manager__switches.h,v 1.3 2025/07/07 09:23:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_manager_switches.h.orig	2025-06-30 06:54:11.000000000 +0000
+++ components/password_manager/core/browser/password_manager_switches.h
@@ -9,7 +9,7 @@
 
 namespace password_manager {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kPasswordStore[];
 extern const char kEnableEncryptionSelection[];
 #endif  // BUILDFLAG(IS_LINUX)
