$NetBSD: patch-components_password__manager_core_browser_password__manager__switches.h,v 1.24 2026/08/09 06:31:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_manager_switches.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ components/password_manager/core/browser/password_manager_switches.h
@@ -9,7 +9,7 @@
 
 namespace password_manager {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kPasswordStore[];
 extern const char kEnableEncryptionSelection[];
 #endif  // BUILDFLAG(IS_LINUX)
