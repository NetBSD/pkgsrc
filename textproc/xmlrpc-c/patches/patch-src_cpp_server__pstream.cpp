$NetBSD: patch-src_cpp_server__pstream.cpp,v 1.1 2019/10/13 21:48:58 he Exp $

Socket functions need sys/types.h on MirBSD.

--- src/cpp/server_pstream.cpp.orig	2014-12-28 18:55:09.000000000 +0000
+++ src/cpp/server_pstream.cpp
@@ -22,6 +22,7 @@
 #include <winsock2.h>
 typedef int socklen_t;
 #else
+#include <sys/types.h>
 #include <sys/socket.h>
 #endif
 #include <errno.h>
