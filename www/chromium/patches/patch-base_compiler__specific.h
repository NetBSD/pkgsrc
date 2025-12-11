$NetBSD: patch-base_compiler__specific.h,v 1.11 2025/12/11 09:13:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/compiler_specific.h.orig	2025-11-19 21:40:05.000000000 +0000
+++ base/compiler_specific.h
@@ -733,6 +733,8 @@ inline constexpr bool AnalyzerAssumeTrue
 #if __has_cpp_attribute(clang::preserve_most) &&             \
     (defined(ARCH_CPU_ARM64) || defined(ARCH_CPU_X86_64)) && \
     !defined(COMPONENT_BUILD) &&                             \
+    !BUILDFLAG(IS_OPENBSD) &&                                \
+    !BUILDFLAG(IS_NETBSD) &&                                 \
     !(BUILDFLAG(IS_WIN) && defined(ARCH_CPU_ARM64))
 #define PRESERVE_MOST [[clang::preserve_most]]
 #else
