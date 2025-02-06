$NetBSD: patch-third__party_swiftshader_third__party_marl_src_thread.cpp,v 1.1 2025/02/06 09:58:28 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/swiftshader/third_party/marl/src/thread.cpp.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/swiftshader/third_party/marl/src/thread.cpp
@@ -46,6 +46,9 @@
 #include <unistd.h>
 #include <thread>
 #endif
+#if defined(__NetBSD__)
+#include <stdarg.h>
+#endif
 
 namespace {
 
@@ -444,7 +447,9 @@ void Thread::setName(const char* fmt, ..
   pthread_setname_np(name);
 #elif defined(__FreeBSD__)
   pthread_set_name_np(pthread_self(), name);
-#elif !defined(__Fuchsia__) && !defined(__EMSCRIPTEN__)
+#elif defined(__NetBSD__)
+  pthread_setname_np(pthread_self(), "%s", (void *)name);
+#elif !defined(__Fuchsia__) && !defined(__EMSCRIPTEN__) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
   pthread_setname_np(pthread_self(), name);
 #endif
 
