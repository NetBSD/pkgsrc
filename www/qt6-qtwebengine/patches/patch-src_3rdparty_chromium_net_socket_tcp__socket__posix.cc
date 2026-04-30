$NetBSD: patch-src_3rdparty_chromium_net_socket_tcp__socket__posix.cc,v 1.2 2026/04/30 06:39:41 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/net/socket/tcp_socket_posix.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/net/socket/tcp_socket_posix.cc
@@ -6,6 +6,9 @@
 
 #include <errno.h>
 #include <netinet/tcp.h>
+#if BUILDFLAG(IS_NETBSD)
+#include <netinet/in.h>
+#endif
 #include <sys/socket.h>
 
 #include <algorithm>
@@ -99,6 +102,17 @@ bool SetTCPKeepAlive(int fd, bool enable
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
 
