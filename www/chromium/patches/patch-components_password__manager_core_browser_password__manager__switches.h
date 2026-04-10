$NetBSD: patch-components_password__manager_core_browser_password__manager__switches.h,v 1.17 2026/04/10 17:31:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_manager_switches.h.orig	2026-04-06 16:25:54.000000000 +0000
+++ components/password_manager/core/browser/password_manager_switches.h
@@ -9,7 +9,7 @@
 
 namespace password_manager {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kPasswordStore[];
 extern const char kEnableEncryptionSelection[];
 #endif  // BUILDFLAG(IS_LINUX)
