$NetBSD: patch-MString.H,v 1.1 2011/11/25 22:19:56 joerg Exp $

--- MString.H.orig	2011-11-25 18:07:40.000000000 +0000
+++ MString.H
@@ -66,7 +66,7 @@
 #ifndef ___STRING_H___
 #define ___STRING_H___
 
-#include <iostream.h>
+#include <iostream>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -75,6 +75,7 @@
 
 #include "Define.H"
 
+using namespace std;
 
 //#define STRING_DEBUG
 
