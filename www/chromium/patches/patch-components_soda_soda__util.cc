$NetBSD: patch-components_soda_soda__util.cc,v 1.29 2026/10/13 13:16:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/soda/soda_util.cc.orig	2026-10-06 00:06:58.000000000 +0000
+++ components/soda/soda_util.cc
@@ -39,7 +39,7 @@ bool IsSupportedChromeOS() {
 }
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
 bool IsSupportedLinux() {
 #if defined(ARCH_CPU_X86_FAMILY)
   // Check if the CPU has the required instruction set to run the Speech
@@ -91,7 +91,7 @@ bool IsOnDeviceSpeechRecognitionSupporte
   // support Gemini Nano.
 #if BUILDFLAG(IS_CHROMEOS)
   return IsSupportedChromeOS();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
   return IsSupportedLinux();
 #elif BUILDFLAG(IS_MAC)
   return IsSupportedMac();
