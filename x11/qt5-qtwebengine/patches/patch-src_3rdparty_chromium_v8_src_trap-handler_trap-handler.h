$NetBSD: patch-src_3rdparty_chromium_v8_src_trap-handler_trap-handler.h,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/v8/src/trap-handler/trap-handler.h.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/v8/src/trap-handler/trap-handler.h
@@ -25,6 +25,10 @@ namespace trap_handler {
 #define V8_TRAP_HANDLER_SUPPORTED true
 #elif V8_TARGET_ARCH_X64 && V8_OS_FREEBSD
 #define V8_TRAP_HANDLER_SUPPORTED true
+#elif V8_TARGET_ARCH_X64 && V8_OS_OPENBSD
+#define V8_TRAP_HANDLER_SUPPORTED true
+#elif V8_TARGET_ARCH_X64 && V8_OS_NETBSD
+#define V8_TRAP_HANDLER_SUPPORTED true
 #else
 #define V8_TRAP_HANDLER_SUPPORTED false
 #endif
