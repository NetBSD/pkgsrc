$NetBSD: patch-third__party_vulkan-loader_src_loader_vk__loader__platform.h,v 1.3 2026/09/02 13:13:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/vulkan-loader/src/loader/vk_loader_platform.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ third_party/vulkan-loader/src/loader/vk_loader_platform.h
@@ -360,7 +360,15 @@ static inline char *loader_platform_exec
 
     return buffer;
 }
-#elif defined(__Fuchsia__) || defined(__OpenBSD__)
+#elif defined(__OpenBSD__)
+static inline char *loader_platform_executable_path(char *buffer, size_t size) {
+    if ((buffer = getenv("CHROME_EXE_PATH")) != NULL)
+        return buffer;
+    else
+        buffer = "/usr/local/chrome/chrome";
+  return buffer;
+}
+#elif defined(__Fuchsia__)
 static inline char *loader_platform_executable_path(char *buffer, size_t size) { return NULL; }
 #elif defined(__QNX__)
 
