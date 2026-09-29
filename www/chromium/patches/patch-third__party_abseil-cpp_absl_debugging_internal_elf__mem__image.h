$NetBSD: patch-third__party_abseil-cpp_absl_debugging_internal_elf__mem__image.h,v 1.27 2026/09/29 07:43:03 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h.orig	2026-09-22 00:09:16.000000000 +0000
+++ third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h
@@ -36,7 +36,7 @@
 #if defined(__ELF__) && !defined(__OpenBSD__) && !defined(__QNX__) &&    \
     !defined(__asmjs__) && !defined(__wasm__) && !defined(__HAIKU__) &&  \
     !defined(__sun) && !defined(__VXWORKS__) && !defined(__hexagon__) && \
-    !defined(__XTENSA__)
+    !defined(__XTENSA__) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 #define ABSL_HAVE_ELF_MEM_IMAGE 1
 #endif
 
