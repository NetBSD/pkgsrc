$NetBSD: patch-src_SocketArray.cpp,v 1.1 2014/03/28 14:13:25 prlw1 Exp $

https://sourceforge.net/p/dansguardian/bugs/55/

--- src/SocketArray.cpp.orig	2011-08-02 13:31:45.000000000 +0000
+++ src/SocketArray.cpp
@@ -14,6 +14,7 @@
 
 #include <syslog.h>
 #include <cerrno>
+#include <cstring>
 
 
 // GLOBALS
