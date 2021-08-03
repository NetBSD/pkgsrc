$NetBSD: patch-src_3rdparty_chromium_base_profiler_register__context.h,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/profiler/register_context.h.orig	2020-07-08 21:41:45.000000000 +0000
+++ src/3rdparty/chromium/base/profiler/register_context.h
@@ -17,7 +17,7 @@
 #include <windows.h>
 #elif defined(OS_MACOSX)
 #include <mach/machine/thread_status.h>
-#elif defined(OS_ANDROID) || defined(OS_LINUX)
+#elif defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 #include <sys/ucontext.h>
 #endif
 
