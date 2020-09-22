$NetBSD: patch-libproxy_url.cpp,v 1.1 2020/09/22 18:23:00 bsiegert Exp $

Unbreak compilation after upstream patch.

--- libproxy/url.cpp.orig	2020-09-22 17:58:59.242281079 +0000
+++ libproxy/url.cpp
@@ -34,6 +34,7 @@
 #include <sys/stat.h> // For stat()
 #include <algorithm> // For transform()
 #include <unistd.h>  // For read() close()
+#include <errno.h>
 
 #ifdef WIN32
 #include <io.h>
