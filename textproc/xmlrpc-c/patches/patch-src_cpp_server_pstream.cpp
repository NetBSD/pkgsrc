$NetBSD: patch-src_cpp_server_pstream.cpp,v 1.1 2013/12/01 23:25:31 bsiegert Exp $

Socket functions need sys/types.h on MirBSD.

--- src/cpp/server_pstream.cpp.orig	Thu Sep 19 12:47:06 2013
+++ src/cpp/server_pstream.cpp
@@ -22,6 +22,7 @@
 #include <winsock.h>
 typedef int socklen_t;
 #else
+#include <sys/types.h>
 #include <sys/socket.h>
 #endif
 #include <errno.h>
