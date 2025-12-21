$NetBSD: patch-src_3rdparty_chromium_third__party_webrtc_rtc__base_platform__thread__types.cc,v 1.1 2025/12/21 09:38:45 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/webrtc/rtc_base/platform_thread_types.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/platform_thread_types.cc
@@ -11,7 +11,9 @@
 #include "rtc_base/platform_thread_types.h"
 
 #if defined(WEBRTC_LINUX)
+#if !defined(WEBRTC_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/syscall.h>
 #endif
 
@@ -44,6 +46,8 @@ PlatformThreadId CurrentThreadId() {
   return gettid();
 #elif defined(WEBRTC_FUCHSIA)
   return zx_thread_self();
+#elif defined(WEBRTC_BSD)
+  return reinterpret_cast<uint64_t>(pthread_self());
 #elif defined(WEBRTC_LINUX)
   return syscall(__NR_gettid);
 #elif defined(__EMSCRIPTEN__)
@@ -74,6 +78,7 @@ bool IsThreadRefEqual(const PlatformThre
 }
 
 void SetCurrentThreadName(const char* name) {
+#if !defined(WEBRTC_BSD)
 #if defined(WEBRTC_WIN)
   // The SetThreadDescription API works even if no debugger is attached.
   // The names set with this API also show up in ETW traces. Very handy.
@@ -121,6 +126,7 @@ void SetCurrentThreadName(const char* na
                                               name, strlen(name));
   RTC_DCHECK_EQ(status, ZX_OK);
 #endif
+#endif
 }
 
 }  // namespace rtc
