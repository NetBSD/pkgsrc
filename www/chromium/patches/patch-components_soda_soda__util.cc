$NetBSD: patch-components_soda_soda__util.cc,v 1.19 2026/05/10 15:29:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/soda/soda_util.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/soda/soda_util.cc
@@ -23,7 +23,7 @@
 #include "base/win/windows_version.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_X86_FAMILY)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_X86_FAMILY)
 #include "base/cpu.h"
 #endif
 
@@ -39,7 +39,7 @@ bool IsSupportedChromeOS() {
 }
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsSupportedLinux() {
 #if defined(ARCH_CPU_X86_FAMILY)
   // Check if the CPU has the required instruction set to run the Speech
@@ -67,7 +67,7 @@ bool IsOnDeviceSpeechRecognitionSupporte
   // support Gemini Nano.
 #if BUILDFLAG(IS_CHROMEOS)
   return IsSupportedChromeOS();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return IsSupportedLinux();
 #elif BUILDFLAG(IS_WIN)
   return IsSupportedWin();
