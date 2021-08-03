$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_platform_wtf_container__annotations.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/container_annotations.h.orig	2020-07-15 18:56:04.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/container_annotations.h
@@ -10,7 +10,7 @@
 
 // TODO(ochang): Remove the ARCH_CPU_X86_64 condition to enable this for X86
 // once the crashes there have been fixed: http://crbug.com/461406
-#if defined(ADDRESS_SANITIZER) && defined(OS_LINUX) && defined(ARCH_CPU_X86_64)
+#if defined(ADDRESS_SANITIZER) && (defined(OS_LINUX) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
 #define ANNOTATE_CONTIGUOUS_CONTAINER
 #define ANNOTATE_NEW_BUFFER(buffer, capacity, newSize)                       \
   if (buffer) {                                                              \
