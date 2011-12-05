$NetBSD: patch-src_logger.cpp,v 1.1 2011/12/05 22:56:58 joerg Exp $

--- src/logger.cpp.orig	2011-12-05 20:33:20.000000000 +0000
+++ src/logger.cpp
@@ -5,4 +5,5 @@
 
 #include <iostream>
+#include <cstdlib>
 
 #include "logger.h"
