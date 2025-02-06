$NetBSD: patch-v8_src_sandbox_sandbox.cc,v 1.1 2025/02/06 09:58:36 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/sandbox/sandbox.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ v8/src/sandbox/sandbox.cc
@@ -48,7 +48,7 @@ static Address DetermineAddressSpaceLimi
   }
 #endif  // V8_TARGET_ARCH_X64
 
-#if defined(V8_TARGET_ARCH_ARM64) && defined(V8_TARGET_OS_ANDROID)
+#if defined(V8_TARGET_ARCH_ARM64) && (defined(V8_TARGET_OS_ANDROID) || defined(V8_TARGET_OS_OPENBSD))
   // On Arm64 Android assume a 40-bit virtual address space (39 bits for
   // userspace and kernel each) as that appears to be the most common
   // configuration and there seems to be no easy way to retrieve the actual
