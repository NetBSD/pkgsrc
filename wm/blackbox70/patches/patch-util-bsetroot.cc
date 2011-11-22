$NetBSD: patch-util-bsetroot.cc,v 1.1 2011/11/22 20:02:48 joerg Exp $

--- util/bsetroot.cc.orig	2011-11-22 19:00:21.000000000 +0000
+++ util/bsetroot.cc
@@ -31,7 +31,8 @@
 
 #include <X11/Xatom.h>
 #include <stdio.h>
-
+#include <stdlib.h>
+#include <string.h>
 
 // ignore all X errors
 static int x11_error(::Display *, XErrorEvent *)
