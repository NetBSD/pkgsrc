$NetBSD: patch-GLObject.H,v 1.1 2011/11/25 22:19:56 joerg Exp $

--- GLObject.H.orig	2011-11-25 18:07:37.000000000 +0000
+++ GLObject.H
@@ -11,11 +11,13 @@
 #pragma warning(disable : 4051)     // ALPHA
 #endif
 
-#include <iostream.h>
+#include <iostream>
 
 #include "GLextensions.H"
 #include "PnmIO.H"
 
+using namespace std;
+
 
 // for debug
 //#define glNormal3f(x,y,z)	glTexCoord2f(x, y)
