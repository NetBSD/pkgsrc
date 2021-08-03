$NetBSD: patch-src_3rdparty_chromium_v8_src_trap-handler_handler-inside-posix.h,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/v8/src/trap-handler/handler-inside-posix.h.orig	2020-07-15 19:01:44.000000000 +0000
+++ src/3rdparty/chromium/v8/src/trap-handler/handler-inside-posix.h
@@ -12,7 +12,7 @@ namespace v8 {
 namespace internal {
 namespace trap_handler {
 
-#if V8_OS_LINUX || V8_OS_FREEBSD
+#if V8_OS_LINUX || V8_OS_FREEBSD || V8_OS_NETBSD
 constexpr int kOobSignal = SIGSEGV;
 #elif V8_OS_MACOSX
 constexpr int kOobSignal = SIGBUS;
