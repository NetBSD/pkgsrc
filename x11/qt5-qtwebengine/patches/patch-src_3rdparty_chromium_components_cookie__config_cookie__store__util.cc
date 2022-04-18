$NetBSD: patch-src_3rdparty_chromium_components_cookie__config_cookie__store__util.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/cookie_config/cookie_store_util.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/cookie_config/cookie_store_util.cc
@@ -12,7 +12,7 @@
 namespace cookie_config {
 
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 namespace {
 
 // Use the operating system's mechanisms to encrypt cookies before writing
