$NetBSD: patch-src_3rdparty_chromium_v8_src_trap-handler_handler-inside-posix.cc,v 1.2 2023/06/10 18:23:07 adam Exp $

--- src/3rdparty/chromium/v8/src/trap-handler/handler-inside-posix.cc.orig	2022-04-06 13:32:17.000000000 +0000
+++ src/3rdparty/chromium/v8/src/trap-handler/handler-inside-posix.cc
@@ -27,7 +27,7 @@
 
 #include <signal.h>
 
-#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD)
+#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD) || defined(V8_OS_NETBSD)
 #include <ucontext.h>
 #elif V8_OS_MACOSX
 #include <sys/ucontext.h>
@@ -120,6 +120,8 @@ bool TryHandleSignal(int signum, siginfo
     auto* context_ip = &uc->uc_mcontext.mc_rip;
 #elif V8_OS_FREEBSD && V8_HOST_ARCH_ARM64
     auto* context_ip = &uc->uc_mcontext.mc_pc;
+#elif V8_OS_NETBSD
+    auto* context_ip = &_UC_MACHINE_PC(uc);
 #else
 #error Unsupported platform
 #endif
