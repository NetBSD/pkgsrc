$NetBSD: patch-base_threading_platform__thread__internal__posix.cc,v 1.14 2026/01/19 16:14:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/threading/platform_thread_internal_posix.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/threading/platform_thread_internal_posix.cc
@@ -31,10 +31,19 @@ ThreadType NiceValueToThreadTypeForTest(
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
@@ -46,9 +55,15 @@ int GetThreadNiceValue(PlatformThreadId 
   }
 
   return nice_value;
+#endif
 }
 
 bool SetThreadNiceFromType(PlatformThreadId thread_id, ThreadType thread_type) {
+#if BUILDFLAG(IS_BSD)
+  // pledge(2) violation
+  NOTIMPLEMENTED();
+  return true;
+#else
   // setpriority(2) should change the whole thread group's (i.e. process)
   // priority. However, as stated in the bugs section of
   // http://man7.org/linux/man-pages/man2/getpriority.2.html: "under the current
@@ -64,6 +79,7 @@ bool SetThreadNiceFromType(PlatformThrea
     return false;
   }
   return true;
+#endif
 }
 
 }  // namespace base::internal
