$NetBSD: patch-third__party_webrtc_rtc__base_platform__thread__types.cc,v 1.14 2026/01/19 16:14:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/rtc_base/platform_thread_types.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/webrtc/rtc_base/platform_thread_types.cc
@@ -12,11 +12,13 @@
 
 // IWYU pragma: begin_keep
 #if defined(WEBRTC_LINUX)
+#if !defined(WEBRTC_BSD)
 #include <linux/prctl.h>
 #include <sys/prctl.h>
+#endif
 #include <sys/syscall.h>
 
-#if !defined(WEBRTC_ARCH_ARM) && !defined(WEBRTC_ARCH_ARM64)
+#if !defined(WEBRTC_ARCH_ARM) && !defined(WEBRTC_ARCH_ARM64) && !defined(WEBRTC_BSD)
 #include <asm/unistd_64.h>
 #endif
 #endif
@@ -50,6 +52,8 @@ PlatformThreadId CurrentThreadId() {
   return gettid();
 #elif defined(WEBRTC_FUCHSIA)
   return zx_thread_self();
+#elif defined(WEBRTC_BSD)
+  return reinterpret_cast<uint64_t>(pthread_self());
 #elif defined(WEBRTC_LINUX)
   return syscall(__NR_gettid);
 #elif defined(__EMSCRIPTEN__)
@@ -80,6 +84,7 @@ bool IsThreadRefEqual(const PlatformThre
 }
 
 void SetCurrentThreadName(const char* name) {
+#if !defined(WEBRTC_BSD)
 #if defined(WEBRTC_WIN)
   // The SetThreadDescription API works even if no debugger is attached.
   // The names set with this API also show up in ETW traces. Very handy.
@@ -127,6 +132,7 @@ void SetCurrentThreadName(const char* na
                                               name, strlen(name));
   RTC_DCHECK_EQ(status, ZX_OK);
 #endif
+#endif
 }
 
 }  // namespace webrtc
