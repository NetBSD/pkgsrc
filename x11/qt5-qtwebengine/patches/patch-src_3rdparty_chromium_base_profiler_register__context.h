$NetBSD: patch-src_3rdparty_chromium_base_profiler_register__context.h,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/profiler/register_context.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/profiler/register_context.h
@@ -17,7 +17,7 @@
 #include <windows.h>
 #elif defined(OS_APPLE)
 #include <mach/machine/thread_status.h>
-#elif defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <sys/ucontext.h>
 #endif
 
