$NetBSD: patch-src_util.cpp,v 1.1 2011/12/05 22:56:58 joerg Exp $

--- src/util.cpp.orig	2011-12-05 20:33:57.000000000 +0000
+++ src/util.cpp
@@ -10,6 +10,7 @@ extern "C" {
 
 #include <sstream>
 #include <iostream>
+#include <cstdlib>
 
 #include "util.h"
 
