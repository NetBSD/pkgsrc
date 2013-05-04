$NetBSD: patch-client_socket.cpp,v 1.1 2013/05/04 12:59:48 joerg Exp $

--- client/socket.cpp.orig	2013-05-03 22:16:33.000000000 +0000
+++ client/socket.cpp
@@ -25,6 +25,7 @@
 #include <sys/types.h>
 #include <errno.h>
 #include <string.h>
+#include <time.h>
 
 #include <QtCore/QFile>
 #include <QtCore/QDebug>
