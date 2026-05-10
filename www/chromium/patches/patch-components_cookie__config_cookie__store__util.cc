$NetBSD: patch-components_cookie__config_cookie__store__util.cc,v 1.19 2026/05/10 15:29:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/cookie_config/cookie_store_util.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/cookie_config/cookie_store_util.cc
@@ -16,7 +16,7 @@
 namespace cookie_config {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 namespace {
 
 void OnOsCryptReadyOnUi(
