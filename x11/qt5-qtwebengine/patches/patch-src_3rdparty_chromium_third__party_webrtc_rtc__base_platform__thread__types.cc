$NetBSD: patch-src_3rdparty_chromium_third__party_webrtc_rtc__base_platform__thread__types.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/webrtc/rtc_base/platform_thread_types.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/platform_thread_types.cc
@@ -14,6 +14,10 @@
 #include <sys/prctl.h>
 #include <sys/syscall.h>
 #endif
+#if defined(WEBRTC_BSD)
+#include <lwp.h>
+#include <pthread.h>
+#endif
 
 namespace rtc {
 
@@ -31,6 +35,8 @@ PlatformThreadId CurrentThreadId() {
   return syscall(__NR_gettid);
 #elif defined(__EMSCRIPTEN__)
   return static_cast<PlatformThreadId>(pthread_self());
+#elif defined(WEBRTC_BSD)
+  return static_cast<PlatformThreadId>(_lwp_self());
 #else
   // Default implementation for nacl and solaris.
   return reinterpret_cast<PlatformThreadId>(pthread_self());
@@ -81,6 +87,8 @@ void SetCurrentThreadName(const char* na
   prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(name));  // NOLINT
 #elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   pthread_setname_np(name);
+#elif defined(__NetBSD__)
+  pthread_setname_np(pthread_self(), "%s", (void *)name);
 #endif
 }
 
