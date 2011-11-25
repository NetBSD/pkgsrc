$NetBSD: patch-src_Config.cpp,v 1.1 2011/11/25 22:21:28 joerg Exp $

--- src/Config.cpp.orig	2011-11-25 16:58:41.000000000 +0000
+++ src/Config.cpp
@@ -25,6 +25,7 @@
 
 #include "Config.h"
 #include <string>
+#include <strings.h>
 
 #include <iostream>
 using std::cout;
