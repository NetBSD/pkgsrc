$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_platform_wtf_container__annotations.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/container_annotations.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/container_annotations.h
@@ -11,7 +11,7 @@
 // TODO(ochang): Remove the ARCH_CPU_X86_64 condition to enable this for X86
 // once the crashes there have been fixed: http://crbug.com/461406
 #if defined(ADDRESS_SANITIZER) && \
-    (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+    (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
 #define ANNOTATE_CONTIGUOUS_CONTAINER
 #define ANNOTATE_NEW_BUFFER(buffer, capacity, newSize)                       \
   if (buffer) {                                                              \
