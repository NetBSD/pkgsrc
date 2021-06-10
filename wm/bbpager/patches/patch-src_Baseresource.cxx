$NetBSD: patch-src_Baseresource.cxx,v 1.1 2021/06/10 12:48:50 nia Exp $

--- src/Baseresource.cxx.orig	2011-11-25 17:02:36.000000000 +0000
+++ src/Baseresource.cxx
@@ -19,6 +19,7 @@
 // (See the included file COPYING / GPL-2.0)
 //
 
+#include <strings.h>
 #include <string>
 #include "Baseresource.h"
 #include <stdio.h>
