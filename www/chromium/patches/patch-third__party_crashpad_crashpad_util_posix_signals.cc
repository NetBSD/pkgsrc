$NetBSD: patch-third__party_crashpad_crashpad_util_posix_signals.cc,v 1.1 2025/02/06 09:58:25 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/crashpad/crashpad/util/posix/signals.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/crashpad/crashpad/util/posix/signals.cc
@@ -51,7 +51,7 @@ constexpr int kCrashSignals[] = {
 #if defined(SIGEMT)
     SIGEMT,
 #endif  // defined(SIGEMT)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     SIGXCPU,
     SIGXFSZ,
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -91,7 +91,7 @@ constexpr int kTerminateSignals[] = {
     SIGXCPU,
     SIGXFSZ,
 #endif  // BUILDFLAG(IS_APPLE)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     SIGIO,
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 };
@@ -251,8 +251,12 @@ bool Signals::WillSignalReraiseAutonomou
          // remains. See 10.12.3 xnu-3789.41.3/bsd/kern/kern_sig.c
          // psignal_internal().
          (code > 0 &&
+#if defined(SI_ASYNCIO)
           code != SI_ASYNCIO &&
+#endif
+#if defined(SI_MESGQ)
           code != SI_MESGQ &&
+#endif
           code != SI_QUEUE &&
           code != SI_TIMER &&
           code != SI_USER &&
