$NetBSD: patch-components_soda_soda__util.cc,v 1.14 2026/01/19 16:14:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/soda/soda_util.cc.orig	2026-01-07 00:50:30.000000000 +0000
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
@@ -73,7 +73,7 @@ bool IsOnDeviceSpeechRecognitionSupporte
   // support Gemini Nano.
 #if BUILDFLAG(IS_CHROMEOS)
   return IsSupportedChromeOS();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return IsSupportedLinux();
 #elif BUILDFLAG(IS_WIN)
   return IsSupportedWin();
