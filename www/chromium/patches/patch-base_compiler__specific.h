$NetBSD: patch-base_compiler__specific.h,v 1.1 2025/02/06 09:57:39 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/compiler_specific.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ base/compiler_specific.h
@@ -683,7 +683,7 @@ inline constexpr bool AnalyzerAssumeTrue
 #if __has_cpp_attribute(clang::preserve_most) &&             \
     (defined(ARCH_CPU_ARM64) || defined(ARCH_CPU_X86_64)) && \
     !defined(COMPONENT_BUILD) &&                             \
-    !(BUILDFLAG(IS_WIN) && defined(ARCH_CPU_ARM64))
+    !((BUILDFLAG(IS_WIN) || BUILDFLAG(IS_OPENBSD)) && defined(ARCH_CPU_ARM64))
 #define PRESERVE_MOST [[clang::preserve_most]]
 #else
 #define PRESERVE_MOST
