$NetBSD: patch-third__party_abseil-cpp_absl_debugging_internal_elf__mem__image.h,v 1.1 2025/02/06 09:58:22 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h
@@ -35,7 +35,8 @@
 #if defined(__ELF__) && !defined(__OpenBSD__) && !defined(__QNX__) && \
     !defined(__native_client__) && !defined(__asmjs__) &&             \
     !defined(__wasm__) && !defined(__HAIKU__) && !defined(__sun) &&   \
-    !defined(__VXWORKS__) && !defined(__hexagon__)
+    !defined(__VXWORKS__) && !defined(__hexagon__) && !defined(__FreeBSD__) && \
+    !defined(__NetBSD__)
 #define ABSL_HAVE_ELF_MEM_IMAGE 1
 #endif
 
