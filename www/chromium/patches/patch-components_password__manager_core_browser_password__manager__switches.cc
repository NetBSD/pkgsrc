$NetBSD: patch-components_password__manager_core_browser_password__manager__switches.cc,v 1.20 2026/06/01 10:09:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_manager_switches.cc.orig	2026-05-26 20:39:02.000000000 +0000
+++ components/password_manager/core/browser/password_manager_switches.cc
@@ -6,7 +6,7 @@
 
 namespace password_manager {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Specifies which encryption storage backend to use. Possible values are
 // kwallet, kwallet5, kwallet6, gnome-libsecret, basic.
 // Any other value will lead to Chrome detecting the best backend automatically.
