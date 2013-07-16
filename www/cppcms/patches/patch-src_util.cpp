$NetBSD: patch-src_util.cpp,v 1.1 2013/07/16 10:12:48 joerg Exp $

--- src/util.cpp.orig	2013-01-02 22:26:03.000000000 +0000
+++ src/util.cpp
@@ -10,6 +10,7 @@
 #include "http_protocol.h"
 #include <stdio.h>
 #include <iterator>
+#include <ostream>
 #include "md5.h"
 #include "tohex.h"
 
