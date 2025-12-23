$NetBSD: patch-base_threading_platform__thread__internal__posix.cc,v 1.13 2025/12/23 13:22:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/threading/platform_thread_internal_posix.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ base/threading/platform_thread_internal_posix.cc
@@ -31,10 +31,19 @@ ThreadPriorityForTest NiceValueToThreadP
 }
 
 int GetCurrentThreadNiceValue() {
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return 0;
+#else
   return GetThreadNiceValue(PlatformThreadId{0});
+#endif
 }
 
 int GetThreadNiceValue(PlatformThreadId id) {
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return 0;
+#else
   // Need to clear errno before calling getpriority():
   // http://man7.org/linux/man-pages/man2/getpriority.2.html
   errno = 0;
@@ -46,6 +55,7 @@ int GetThreadNiceValue(PlatformThreadId 
   }
 
   return nice_value;
+#endif
 }
 
 }  // namespace base::internal
