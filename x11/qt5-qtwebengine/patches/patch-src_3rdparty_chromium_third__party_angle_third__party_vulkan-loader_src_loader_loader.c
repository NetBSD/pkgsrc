$NetBSD: patch-src_3rdparty_chromium_third__party_angle_third__party_vulkan-loader_src_loader_loader.c,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/third_party/angle/third_party/vulkan-loader/src/loader/loader.c.orig	2020-07-15 19:01:42.000000000 +0000
+++ src/3rdparty/chromium/third_party/angle/third_party/vulkan-loader/src/loader/loader.c
@@ -246,7 +246,7 @@ void *loader_device_heap_realloc(const s
 }
 
 // Environment variables
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 
 static inline bool IsHighIntegrity() {
     return geteuid() != getuid() || getegid() != getgid();
