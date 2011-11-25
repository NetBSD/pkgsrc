$NetBSD: patch-src_resource.cxx,v 1.1 2011/11/25 22:22:05 joerg Exp $

--- src/resource.cxx.orig	2011-11-25 17:02:49.000000000 +0000
+++ src/resource.cxx
@@ -18,7 +18,7 @@
 //
 // (See the included file COPYING / GPL-2.0)
 //
-
+#include <strings.h>
 #include "resource.h"
 #include "blackboxstyle.h"
 
