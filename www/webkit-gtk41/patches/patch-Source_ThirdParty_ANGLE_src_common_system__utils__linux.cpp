$NetBSD: patch-Source_ThirdParty_ANGLE_src_common_system__utils__linux.cpp,v 1.1 2026/08/30 14:25:05 wiz Exp $

pthread_setname_np() has three arguments on NetBSD.

--- Source/ThirdParty/ANGLE/src/common/system_utils_linux.cpp.orig	2025-02-25 08:25:37.951309000 +0000
+++ Source/ThirdParty/ANGLE/src/common/system_utils_linux.cpp
@@ -58,7 +58,10 @@ void SetCurrentThreadName(const char *na
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
