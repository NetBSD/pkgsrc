$NetBSD: patch-src_3rdparty_chromium_third__party_angle_src_common_system__utils__linux.cpp,v 1.1 2025/12/21 09:38:39 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/angle/src/common/system_utils_linux.cpp.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/third_party/angle/src/common/system_utils_linux.cpp
@@ -17,8 +17,15 @@
 
 #include <array>
 
+#if ANGLE_PLATFORM_OPENBSD
+#include <pthread_np.h>
+#elif ANGLE_PLATFORM_NETBSD
+#include <pthread.h>
+#endif
+
 namespace angle
 {
+#if ANGLE_PLATFORM_LINUX
 std::string GetExecutablePath()
 {
     // We cannot use lstat to get the size of /proc/self/exe as it always returns 0
@@ -34,6 +41,7 @@ std::string GetExecutablePath()
     path[result] = '\0';
     return path;
 }
+#endif
 
 std::string GetExecutableDirectory()
 {
@@ -59,6 +67,12 @@ void SetCurrentThreadName(const char *na
     // There's a 15-character (16 including '\0') limit.  If the name is too big (and ERANGE is
     // returned), name will be ignored.
     ASSERT(strlen(name) < 16);
+#if ANGLE_PLATFORM_OPENBSD
+    pthread_set_name_np(pthread_self(), name);
+#elif ANGLE_PLATFORM_NETBSD
+    pthread_setname_np(pthread_self(), "%s", (void *)name);
+#else
     pthread_setname_np(pthread_self(), name);
+#endif
 }
 }  // namespace angle
