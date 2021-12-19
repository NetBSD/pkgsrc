$NetBSD: patch-src_server_wsgi__python.h,v 1.1 2021/12/19 14:12:29 wiz Exp $

Remove reference to non-existent file.

--- src/server/wsgi_python.h.orig	2020-02-16 23:02:48.000000000 +0000
+++ src/server/wsgi_python.h
@@ -41,7 +41,6 @@
 
 #include "structmember.h"
 #include "compile.h"
-#include "node.h"
 #include "osdefs.h"
 #include "frameobject.h"
 
