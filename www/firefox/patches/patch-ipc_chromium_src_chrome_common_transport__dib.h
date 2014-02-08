$NetBSD: patch-ipc_chromium_src_chrome_common_transport__dib.h,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- ipc/chromium/src/chrome/common/transport_dib.h.orig	2014-01-28 04:03:44.000000000 +0000
+++ ipc/chromium/src/chrome/common/transport_dib.h
@@ -70,7 +70,7 @@ class TransportDIB {
   typedef base::SharedMemoryHandle Handle;
   // On Mac, the inode number of the backing file is used as an id.
   typedef base::SharedMemoryId Id;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_SOLARIS)
   typedef int Handle;  // These two ints are SysV IPC shared memory keys
   typedef int Id;
 #endif
