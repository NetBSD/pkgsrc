$NetBSD: patch-src_3rdparty_chromium_third__party_webrtc_rtc__base_platform__thread__types.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/webrtc/rtc_base/platform_thread_types.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/platform_thread_types.cc
@@ -14,6 +14,10 @@
 #include <sys/prctl.h>
 #include <sys/syscall.h>
 #endif
+#if defined(WEBRTC_BSD)
+#include <lwp.h>
+#include <pthread.h>
+#endif
 
 #if defined(WEBRTC_WIN)
 #include "rtc_base/arraysize.h"
@@ -41,6 +45,8 @@ PlatformThreadId CurrentThreadId() {
   return syscall(__NR_gettid);
 #elif defined(__EMSCRIPTEN__)
   return static_cast<PlatformThreadId>(pthread_self());
+#elif defined(WEBRTC_BSD)
+  return static_cast<PlatformThreadId>(_lwp_self());
 #else
   // Default implementation for nacl and solaris.
   return reinterpret_cast<PlatformThreadId>(pthread_self());
@@ -109,6 +115,8 @@ void SetCurrentThreadName(const char* na
   prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(name));  // NOLINT
 #elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   pthread_setname_np(name);
+#elif defined(__NetBSD__)
+  pthread_setname_np(pthread_self(), "%s", (void *)name);
 #endif
 }
 
