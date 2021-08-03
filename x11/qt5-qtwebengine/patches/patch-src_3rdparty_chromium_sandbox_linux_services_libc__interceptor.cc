$NetBSD: patch-src_3rdparty_chromium_sandbox_linux_services_libc__interceptor.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/sandbox/linux/services/libc_interceptor.cc.orig	2020-07-15 18:56:01.000000000 +0000
+++ src/3rdparty/chromium/sandbox/linux/services/libc_interceptor.cc
@@ -11,7 +11,9 @@
 #include <stddef.h>
 #include <stdint.h>
 #include <string.h>
+#if !defined(OS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <time.h>
@@ -93,7 +95,7 @@ bool ReadTimeStruct(base::PickleIterator
   } else {
     base::AutoLock lock(g_timezones_lock.Get());
     auto ret_pair = g_timezones.Get().insert(timezone);
-    output->tm_zone = ret_pair.first->c_str();
+    output->tm_zone = (char *)ret_pair.first->c_str();
   }
 
   return true;
