$NetBSD: patch-src_Image.cc,v 1.1 2011/11/26 17:22:25 joerg Exp $

--- src/Image.cc.orig	2011-11-26 14:37:13.000000000 +0000
+++ src/Image.cc
@@ -29,6 +29,7 @@
 #  include <stdio.h>
 #endif // HAVE_STDIO_H
 
+#include <cstring>
 #include <algorithm>
 using std::max;
 using std::min;
