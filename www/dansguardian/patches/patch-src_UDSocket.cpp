$NetBSD: patch-src_UDSocket.cpp,v 1.1 2014/03/28 14:13:25 prlw1 Exp $

https://sourceforge.net/p/dansguardian/bugs/55/

--- src/UDSocket.cpp.orig	2012-09-29 20:06:45.000000000 +0000
+++ src/UDSocket.cpp
@@ -18,6 +18,7 @@
 #include <sys/time.h>
 #include <pwd.h>
 #include <cerrno>
+#include <cstring>
 #include <unistd.h>
 #include <stdexcept>
 #include <stddef.h>
