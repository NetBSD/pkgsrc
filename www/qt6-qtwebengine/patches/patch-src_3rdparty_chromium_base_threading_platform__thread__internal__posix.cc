$NetBSD: patch-src_3rdparty_chromium_base_threading_platform__thread__internal__posix.cc,v 1.2 2026/04/30 06:39:35 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/threading/platform_thread_internal_posix.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/base/threading/platform_thread_internal_posix.cc
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
