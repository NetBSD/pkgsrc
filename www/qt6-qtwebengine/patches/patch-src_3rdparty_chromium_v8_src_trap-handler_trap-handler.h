$NetBSD: patch-src_3rdparty_chromium_v8_src_trap-handler_trap-handler.h,v 1.2 2026/04/30 06:39:46 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/v8/src/trap-handler/trap-handler.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/v8/src/trap-handler/trap-handler.h
@@ -18,7 +18,7 @@ namespace v8::internal::trap_handler {
 // X64 on Linux, Windows, MacOS, FreeBSD.
 #if V8_HOST_ARCH_X64 && V8_TARGET_ARCH_X64 &&                        \
     ((V8_OS_LINUX && !V8_OS_ANDROID) || V8_OS_WIN || V8_OS_DARWIN || \
-     V8_OS_FREEBSD)
+     V8_OS_FREEBSD || V8_OS_OPENBSD || V8_OS_NETBSD)
 #define V8_TRAP_HANDLER_SUPPORTED true
 // Arm64 native on Linux, Windows, MacOS.
 #elif V8_TARGET_ARCH_ARM64 && V8_HOST_ARCH_ARM64 && \
