$NetBSD: patch-net_socket_tcp__socket__posix.cc,v 1.14 2026/01/19 16:14:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/socket/tcp_socket_posix.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ net/socket/tcp_socket_posix.cc
@@ -6,6 +6,9 @@
 
 #include <errno.h>
 #include <netinet/tcp.h>
+#if BUILDFLAG(IS_NETBSD)
+#include <netinet/in.h>
+#endif
 #include <sys/socket.h>
 
 #include <algorithm>
@@ -97,6 +100,17 @@ bool SetTCPKeepAlive(int fd, bool enable
       PLOG(ERROR) << "Failed to set TCP_KEEPALIVE on fd: " << fd;
       return false;
     }
+#elif BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
+  // Set seconds until first TCP keep alive.
+  if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPIDLE, &delay, sizeof(delay))) {
+    PLOG(ERROR) << "Failed to set TCP_KEEPIDLE on fd: " << fd;
+    return false;
+  }
+  // Set seconds between TCP keep alives.  
+  if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPINTVL, &delay, sizeof(delay))) {
+    PLOG(ERROR) << "Failed to set TCP_KEEPINTVL on fd: " << fd;
+    return false;
+  }
 #endif
   }
 
