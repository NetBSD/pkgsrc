$NetBSD: patch-src_3rdparty_chromium_v8_src_trap-handler_handler-inside-posix.h,v 1.1 2025/12/21 09:38:51 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/v8/src/trap-handler/handler-inside-posix.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/v8/src/trap-handler/handler-inside-posix.h
@@ -13,7 +13,7 @@ namespace v8 {
 namespace internal {
 namespace trap_handler {
 
-#if V8_OS_LINUX || V8_OS_FREEBSD
+#if V8_OS_LINUX || V8_OS_FREEBSD || V8_OS_OPENBSD || V8_OS_NETBSD
 constexpr int kOobSignal = SIGSEGV;
 #elif V8_OS_DARWIN
 constexpr int kOobSignal = SIGBUS;
