$NetBSD: patch-v8_src_trap-handler_handler-inside-posix.h,v 1.25 2026/09/02 13:13:40 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/trap-handler/handler-inside-posix.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ v8/src/trap-handler/handler-inside-posix.h
@@ -13,7 +13,7 @@ namespace v8 {
 namespace internal {
 namespace trap_handler {
 
-#if V8_OS_LINUX || V8_OS_FREEBSD
+#if V8_OS_LINUX || V8_OS_FREEBSD || V8_OS_OPENBSD || V8_OS_NETBSD
 constexpr int kOobSignal = SIGSEGV;
 #elif V8_OS_DARWIN
 constexpr int kOobSignal = SIGBUS;
