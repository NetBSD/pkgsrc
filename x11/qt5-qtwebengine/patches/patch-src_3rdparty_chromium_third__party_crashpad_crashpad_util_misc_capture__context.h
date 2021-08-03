$NetBSD: patch-src_3rdparty_chromium_third__party_crashpad_crashpad_util_misc_capture__context.h,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/crashpad/crashpad/util/misc/capture_context.h.orig	2020-07-15 18:56:30.000000000 +0000
+++ src/3rdparty/chromium/third_party/crashpad/crashpad/util/misc/capture_context.h
@@ -21,7 +21,7 @@
 #include <mach/mach.h>
 #elif defined(OS_WIN)
 #include <windows.h>
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #include <ucontext.h>
 #elif defined(OS_FUCHSIA)
 #include <signal.h>
@@ -37,7 +37,7 @@ using NativeCPUContext = arm_unified_thr
 #endif
 #elif defined(OS_WIN)
 using NativeCPUContext = CONTEXT;
-#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
 using NativeCPUContext = ucontext_t;
 #endif  // OS_MACOSX
 
