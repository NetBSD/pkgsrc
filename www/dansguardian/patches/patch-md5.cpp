$NetBSD: patch-md5.cpp,v 1.1 2013/12/10 12:35:41 jperkin Exp $

Avoid __ENDIANH on SunOS.

--- md5.cpp.orig	2005-08-13 23:47:57.000000000 +0000
+++ md5.cpp
@@ -30,7 +30,9 @@
 //These lines modified Tue 24th February 2004 by Daniel Barron
 #include "autoconf/platform.h"
 #ifdef __ENDIANH
-    #include __ENDIANH
+    #if !defined(__sun)
+        #include __ENDIANH
+    #endif
 #else
     #include <endian.h>
 #endif
