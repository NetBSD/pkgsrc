$NetBSD: patch-src_ImageContainer.cpp,v 1.1 2014/03/28 14:13:25 prlw1 Exp $

https://sourceforge.net/p/dansguardian/bugs/55/

--- src/ImageContainer.cpp.orig	2012-09-29 20:06:45.000000000 +0000
+++ src/ImageContainer.cpp
@@ -15,6 +15,7 @@
 #include <fstream>
 #include <stdexcept>
 #include <cerrno>
+#include <cstring>
 #include <limits.h>
 
 
