$NetBSD: patch-base_threading_platform__thread__internal__posix.cc,v 1.6 2025/09/08 13:24:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/threading/platform_thread_internal_posix.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ base/threading/platform_thread_internal_posix.cc
@@ -31,6 +31,10 @@ ThreadPriorityForTest NiceValueToThreadP
 }
 
 int GetCurrentThreadNiceValue() {
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return 0;
+#else
   // Need to clear errno before calling getpriority():
   // http://man7.org/linux/man-pages/man2/getpriority.2.html
   errno = 0;
@@ -42,6 +46,7 @@ int GetCurrentThreadNiceValue() {
   }
 
   return nice_value;
+#endif
 }
 
 }  // namespace base::internal
