$NetBSD: patch-third__party_libwebrtc_rtc__base_platform__thread__types.cc,v 1.2 2025/07/23 13:57:35 ryoon Exp $

--- third_party/libwebrtc/rtc_base/platform_thread_types.cc.orig	2025-05-21 12:30:11.564823191 +0000
+++ third_party/libwebrtc/rtc_base/platform_thread_types.cc
@@ -71,7 +71,11 @@ bool IsThreadRefEqual(const PlatformThre
 #if defined(WEBRTC_WIN) || defined(WEBRTC_FUCHSIA)
   return a == b;
 #elif defined(WEBRTC_POSIX)
+#  if defined(__NetBSD__)
+  return a == b;
+#  else
   return pthread_equal(a, b);
+#  endif
 #endif
 }
 
@@ -118,6 +122,12 @@ void SetCurrentThreadName(const char* na
   prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(name));  // NOLINT
 #elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   pthread_setname_np(name);
+#elif defined(WEBRTC_BSD)
+#  if defined(__NetBSD__)
+  pthread_setname_np(pthread_self(), "%s", const_cast<char *>(name));
+#  else
+  pthread_setname_np(pthread_self(), name);
+#  endif
 #elif defined(WEBRTC_FUCHSIA)
   zx_status_t status = zx_object_set_property(zx_thread_self(), ZX_PROP_NAME,
                                               name, strlen(name));
