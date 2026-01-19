$NetBSD: patch-v8_src_trap-handler_handler-inside-posix.cc,v 1.14 2026/01/19 16:14:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/trap-handler/handler-inside-posix.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ v8/src/trap-handler/handler-inside-posix.cc
@@ -28,7 +28,7 @@
 
 #include <signal.h>
 
-#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD)
+#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD) || defined(V8_OS_NETBSD)
 #include <ucontext.h>
 #elif V8_OS_DARWIN
 #include <sys/ucontext.h>
@@ -62,6 +62,10 @@ namespace trap_handler {
 #define CONTEXT_REG(reg, REG) &uc->uc_mcontext->__ss.__##reg
 #elif V8_OS_FREEBSD
 #define CONTEXT_REG(reg, REG) &uc->uc_mcontext.mc_##reg
+#elif V8_OS_OPENBSD
+#define CONTEXT_REG(reg, REG) &uc->sc_##reg
+#elif V8_OS_NETBSD
+#define CONTEXT_REG(reg, REG) &uc->uc_mcontext.__gregs[_REG_##REG]
 #else
 #error "Unsupported platform."
 #endif
@@ -81,8 +85,12 @@ bool IsKernelGeneratedSignal(siginfo_t* 
   // si_code at its default of 0 for signals that don’t originate in hardware.
   // The other conditions are only relevant for Linux.
   return info->si_code > 0 && info->si_code != SI_USER &&
-         info->si_code != SI_QUEUE && info->si_code != SI_TIMER &&
-         info->si_code != SI_ASYNCIO && info->si_code != SI_MESGQ;
+         info->si_code != SI_QUEUE && info->si_code != SI_TIMER
+#ifdef V8_OS_OPENBSD
+         ;
+#else
+         && info->si_code != SI_ASYNCIO && info->si_code != SI_MESGQ;
+#endif
 }
 
 class UnmaskOobSignalScope {
