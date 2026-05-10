$NetBSD: patch-third__party_test__fonts_fontconfig_generate__fontconfig__caches.cc,v 1.19 2026/05/10 15:30:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/test_fonts/fontconfig/generate_fontconfig_caches.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ third_party/test_fonts/fontconfig/generate_fontconfig_caches.cc
@@ -28,6 +28,7 @@ int main() {
   // fontconfig cache.
   //     $ echo -n /test_fonts | md5sum
   //     fb5c91b2895aa445d23aebf7f9e2189c  -
+  //static const char kCacheKey[] = "cd4b5bc7-6cfc-41dc-8982-f2db624179ba";
   static const char kCacheKey[] = "fb5c91b2895aa445d23aebf7f9e2189c";
 
   // fontconfig writes the mtime of the test_fonts directory into the cache. It
@@ -56,7 +57,8 @@ int main() {
   FcFini();
 
   // Check existence of intended fontconfig cache file.
-  auto cache = fontconfig_caches + "/" + kCacheKey + "-le64.cache-11";
+  //auto cache = fontconfig_caches + "/" + kCacheKey + "-x86_64.cache-" + FC_CACHE_VERSION;
+  auto cache = fontconfig_caches + "/" + kCacheKey + "-le64.cache-" + FC_CACHE_VERSION;
   bool cache_exists = access(cache.c_str(), F_OK) == 0;
   return !cache_exists;
 }
