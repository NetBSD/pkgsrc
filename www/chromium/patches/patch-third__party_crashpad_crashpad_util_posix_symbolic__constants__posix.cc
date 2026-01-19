$NetBSD: patch-third__party_crashpad_crashpad_util_posix_symbolic__constants__posix.cc,v 1.14 2026/01/19 16:14:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/crashpad/crashpad/util/posix/symbolic_constants_posix.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/crashpad/crashpad/util/posix/symbolic_constants_posix.cc
@@ -68,7 +68,7 @@ constexpr const char* kSignalNames[] = {
     "INFO",
     "USR1",
     "USR2",
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #if defined(ARCH_CPU_MIPS_FAMILY)
     "HUP",
     "INT",
@@ -139,7 +139,7 @@ constexpr const char* kSignalNames[] = {
 #endif  // defined(ARCH_CPU_MIPS_FAMILY)
 #endif
 };
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // NSIG is 64 to account for real-time signals.
 static_assert(std::size(kSignalNames) == 32, "kSignalNames length");
 #else
