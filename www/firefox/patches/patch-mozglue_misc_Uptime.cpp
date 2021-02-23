$NetBSD: patch-mozglue_misc_Uptime.cpp,v 1.1 2021/02/23 17:02:04 ryoon Exp $

* Define uptime-related functions for NetBSD too.

--- mozglue/misc/Uptime.cpp.orig	2021-02-11 21:17:44.000000000 +0000
+++ mozglue/misc/Uptime.cpp
@@ -79,7 +79,7 @@ Maybe<uint64_t> NowIncludingSuspendMs() 
 }
 #endif  // XP_WIN
 
-#if defined(XP_LINUX)  // including Android
+#if defined(XP_UNIX) && !(defined(__APPLE__) && defined(__MACH__)) // including Android
 #  include <time.h>
 
 // Number of nanoseconds in a millisecond.
