$NetBSD: patch-third__party_angle_src_common_system__utils__linux.cpp,v 1.14 2026/01/19 16:14:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/angle/src/common/system_utils_linux.cpp.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/angle/src/common/system_utils_linux.cpp
@@ -19,10 +19,17 @@
 #include <sys/types.h>
 #include <unistd.h>
 
+#if ANGLE_PLATFORM_OPENBSD
+#include <pthread_np.h>
+#elif ANGLE_PLATFORM_NETBSD
+#include <pthread.h>
+#endif
+
 #include <array>
 
 namespace angle
 {
+#if ANGLE_PLATFORM_LINUX
 std::string GetExecutablePath()
 {
     // We cannot use lstat to get the size of /proc/self/exe as it always returns 0
@@ -38,6 +45,7 @@ std::string GetExecutablePath()
     path[result] = '\0';
     return path;
 }
+#endif
 
 std::string GetExecutableDirectory()
 {
@@ -63,6 +71,12 @@ void SetCurrentThreadName(const char *na
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
