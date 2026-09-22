$NetBSD: patch-Source_ThirdParty_ANGLE_src_common_system__utils__linux.cpp,v 1.2 2026/09/22 12:27:02 wiz Exp $

NetBSD doesn't provide CLOCK_MONOTONIC_RAW.
pthread_setname_np() has three arguments on NetBSD.

--- Source/ThirdParty/ANGLE/src/common/system_utils_linux.cpp.orig	2026-09-11 05:47:59.581623300 +0000
+++ Source/ThirdParty/ANGLE/src/common/system_utils_linux.cpp
@@ -18,6 +18,10 @@
 
 #include <array>
 
+#ifndef CLOCK_MONOTONIC_RAW
+#define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC
+#endif
+
 namespace angle
 {
 std::string GetExecutablePath()
@@ -66,7 +70,10 @@ void SetCurrentThreadName(const char *name)
 {
     // There's a 15-character (16 including '\0') limit.  If the name is too big (and ERANGE is
     // returned), name will be ignored.
-    ASSERT(strlen(name) < 16);
+#ifdef __NetBSD__
+    pthread_setname_np(pthread_self(), "%s", (void *)name);
+#else
     pthread_setname_np(pthread_self(), name);
+#endif
 }
 }  // namespace angle
