$NetBSD: patch-mozglue_misc_Uptime.cpp,v 1.1 2022/07/21 23:56:39 nia Exp $

* Define uptime-related functions for NetBSD too.

--- mozglue/misc/Uptime.cpp.orig	2021-05-20 21:29:40.000000000 +0000
+++ mozglue/misc/Uptime.cpp
@@ -76,7 +76,7 @@ Maybe<uint64_t> NowIncludingSuspendMs() 
   return Some(interrupt_time / kHNSperMS);
 }
 
-#elif defined(XP_LINUX)  // including Android
+#elif defined(OS_LINUX) || defined(XP_UNIX)  // including Android
 #  include <time.h>
 
 // Number of nanoseconds in a millisecond.
