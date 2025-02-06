$NetBSD: patch-third__party_crashpad_crashpad_util_misc_capture__context.h,v 1.1 2025/02/06 09:58:25 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/crashpad/crashpad/util/misc/capture_context.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/crashpad/crashpad/util/misc/capture_context.h
@@ -21,7 +21,8 @@
 #include <mach/mach.h>
 #elif BUILDFLAG(IS_WIN)
 #include <windows.h>
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
+      BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
 #include <ucontext.h>
 #endif  // BUILDFLAG(IS_APPLE)
 
@@ -35,7 +36,8 @@ using NativeCPUContext = arm_unified_thr
 #endif
 #elif BUILDFLAG(IS_WIN)
 using NativeCPUContext = CONTEXT;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
+      BUILDFLAG(IS_BSD)
 using NativeCPUContext = ucontext_t;
 #endif  // BUILDFLAG(IS_APPLE)
 
