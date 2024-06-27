$NetBSD: patch-src_Logger.cpp,v 1.1 2024/06/27 15:26:23 sborrill Exp $

Include cstring for memset()

--- src/Logger.cpp.orig	2024-03-28 12:29:24.067939042 +0000
+++ src/Logger.cpp	2024-03-28 12:41:12.393125789 +0000
@@ -15,6 +15,7 @@
 #include <fstream>
 #include <sstream>
 #include <string>
+#include <cstring>
 #include <syslog.h>
 #include <cstdio>
 #include <sys/socket.h>
