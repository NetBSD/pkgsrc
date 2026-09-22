$NetBSD: patch-third__party_vulkan-loader_src_loader_vk__loader__platform.h,v 1.4 2026/09/22 13:41:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/vulkan-loader/src/loader/vk_loader_platform.h.orig	2026-09-14 22:17:16.000000000 +0000
+++ third_party/vulkan-loader/src/loader/vk_loader_platform.h
@@ -29,6 +29,7 @@
 #if defined(__FreeBSD__) || defined(__OpenBSD__)
 #include <sys/types.h>
 #include <sys/select.h>
+#include <sys/param.h>
 #endif
 
 #include <assert.h>
@@ -360,7 +361,23 @@ static inline char *loader_platform_exec
 
     return buffer;
 }
-#elif defined(__Fuchsia__) || defined(__OpenBSD__)
+#elif defined(__OpenBSD__)
+static inline char *loader_platform_executable_path(char *buffer, size_t size) {
+#if (OpenBSD >= 202610)
+    char execpath[PATH_MAX];
+    if (getexecpath(execpath, sizeof(execpath)) != 0) {
+        return NULL;
+    }
+    *buffer = execpath;
+#else
+    if ((buffer = getenv("CHROME_EXE_PATH")) != NULL)
+        return buffer;
+    else
+        buffer = "/usr/local/chrome/chrome";
+#endif
+  return buffer;
+}
+#elif defined(__Fuchsia__)
 static inline char *loader_platform_executable_path(char *buffer, size_t size) { return NULL; }
 #elif defined(__QNX__)
 
