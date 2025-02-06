$NetBSD: patch-components_cookie__config_cookie__store__util.cc,v 1.1 2025/02/06 09:57:58 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/cookie_config/cookie_store_util.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/cookie_config/cookie_store_util.cc
@@ -12,7 +12,7 @@
 namespace cookie_config {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 namespace {
 
 // Use the operating system's mechanisms to encrypt cookies before writing
