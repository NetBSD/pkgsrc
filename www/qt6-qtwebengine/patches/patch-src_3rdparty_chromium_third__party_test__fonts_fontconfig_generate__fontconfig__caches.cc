$NetBSD: patch-src_3rdparty_chromium_third__party_test__fonts_fontconfig_generate__fontconfig__caches.cc,v 1.2 2026/04/30 06:39:44 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/test_fonts/fontconfig/generate_fontconfig_caches.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/third_party/test_fonts/fontconfig/generate_fontconfig_caches.cc
@@ -28,7 +28,7 @@ int main() {
   // fontconfig cache.
   //     $ echo -n /test_fonts | md5sum
   //     fb5c91b2895aa445d23aebf7f9e2189c  -
-  static const char kCacheKey[] = "fb5c91b2895aa445d23aebf7f9e2189c";
+  static const char kCacheKey[] = "cd4b5bc7-6cfc-41dc-8982-f2db624179ba";
 
   // fontconfig writes the mtime of the test_fonts directory into the cache. It
   // presumably checks this later to ensure that the cache is still up to date.
@@ -56,7 +56,7 @@ int main() {
   FcFini();
 
   // Check existence of intended fontconfig cache file.
-  auto cache = fontconfig_caches + "/" + kCacheKey + "-le64.cache-reindex1-10";
+  auto cache = fontconfig_caches + "/" + kCacheKey + "-x86_64.cache-" + FC_CACHE_VERSION;
   bool cache_exists = access(cache.c_str(), F_OK) == 0;
   return !cache_exists;
 }
