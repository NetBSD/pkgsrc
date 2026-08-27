$NetBSD: patch-mozglue_misc_Now.cpp,v 1.1 2026/08/27 01:23:17 gutteridge Exp $

* If CLOCK_BOOTTIME is not available, return 0 instead of Nothing().
  This fixes incorrect assert at AudioSessionManager.cpp:57 introduced
  in 153.0.

--- mozglue/misc/Now.cpp.orig	2026-07-23 01:36:06.678846874 +0000
+++ mozglue/misc/Now.cpp
@@ -89,16 +89,13 @@ Maybe<uint64_t> NowIncludingSuspendMs() {
 }
 
 Maybe<uint64_t> NowIncludingSuspendMs() {
-#  ifndef CLOCK_BOOTTIME
-  return Nothing();
-#  else
   struct timespec ts = {0};
-
+#  ifdef CLOCK_BOOTTIME
   if (clock_gettime(CLOCK_BOOTTIME, &ts)) {
     return Nothing();
   }
-  return Some(TimespecToMilliseconds(ts));
 #  endif
+  return Some(TimespecToMilliseconds(ts));
 }
 
 #else  // catch all
