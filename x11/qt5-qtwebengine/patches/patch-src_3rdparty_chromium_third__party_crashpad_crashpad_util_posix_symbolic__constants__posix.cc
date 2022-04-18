$NetBSD: patch-src_3rdparty_chromium_third__party_crashpad_crashpad_util_posix_symbolic__constants__posix.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/crashpad/crashpad/util/posix/symbolic_constants_posix.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/third_party/crashpad/crashpad/util/posix/symbolic_constants_posix.cc
@@ -64,7 +64,7 @@ constexpr const char* kSignalNames[] = {
     "INFO",
     "USR1",
     "USR2",
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 #if defined(ARCH_CPU_MIPS_FAMILY)
     "HUP",
     "INT",
@@ -135,7 +135,7 @@ constexpr const char* kSignalNames[] = {
 #endif  // defined(ARCH_CPU_MIPS_FAMILY)
 #endif
 };
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 // NSIG is 64 to account for real-time signals.
 static_assert(base::size(kSignalNames) == 32, "kSignalNames length");
 #else
