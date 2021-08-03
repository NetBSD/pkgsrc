$NetBSD: patch-src_3rdparty_chromium_base_trace__event_malloc__dump__dump__provider.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/trace_event/malloc_dump_provider.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/trace_event/malloc_dump_provider.cc
@@ -17,6 +17,8 @@
 
 #if defined(OS_MACOSX)
 #include <malloc/malloc.h>
+#elif defined(OS_FREEBSD) || defined(OS_NETBSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -132,6 +134,9 @@ bool MallocDumpProvider::OnMemoryDump(co
   }
 #elif defined(OS_FUCHSIA)
 // TODO(fuchsia): Port, see https://crbug.com/706592.
+#elif defined(OS_BSD)
+  total_virtual_size = 0;
+  allocated_objects_size = 0;
 #else
   struct mallinfo info = mallinfo();
   // In case of Android's jemalloc |arena| is 0 and the outer pages size is
