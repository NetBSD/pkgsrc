$NetBSD: patch-src_3rdparty_chromium_v8_src_trap-handler_handler-inside-posix.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/v8/src/trap-handler/handler-inside-posix.cc.orig	2020-07-15 19:01:44.000000000 +0000
+++ src/3rdparty/chromium/v8/src/trap-handler/handler-inside-posix.cc
@@ -27,7 +27,7 @@
 
 #include <signal.h>
 
-#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD)
+#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD) || defined(V8_OS_NETBSD)
 #include <ucontext.h>
 #elif V8_OS_MACOSX
 #include <sys/ucontext.h>
@@ -114,6 +114,8 @@ bool TryHandleSignal(int signum, siginfo
     auto* context_rip = &uc->uc_mcontext->__ss.__rip;
 #elif V8_OS_FREEBSD
     auto* context_rip = &uc->uc_mcontext.mc_rip;
+#elif V8_OS_NETBSD
+    auto* context_rip = &_UC_MACHINE_PC(uc);
 #else
 #error Unsupported platform
 #endif
