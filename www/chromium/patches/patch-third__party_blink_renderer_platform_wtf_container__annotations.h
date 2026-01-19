$NetBSD: patch-third__party_blink_renderer_platform_wtf_container__annotations.h,v 1.14 2026/01/19 16:14:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/wtf/container_annotations.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/blink/renderer/platform/wtf/container_annotations.h
@@ -11,7 +11,7 @@
 // TODO(ochang): Remove the ARCH_CPU_X86_64 condition to enable this for X86
 // once the crashes there have been fixed: http://crbug.com/461406
 #if defined(ADDRESS_SANITIZER) &&                      \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
     defined(ARCH_CPU_X86_64)
 
 // Annotations require buffers to begin on an 8-byte boundary. See
