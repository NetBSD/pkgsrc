$NetBSD: patch-lib-Resource.cc,v 1.1 2011/11/22 20:02:48 joerg Exp $

--- lib/Resource.cc.orig	2011-11-22 18:36:20.000000000 +0000
+++ lib/Resource.cc
@@ -29,6 +29,7 @@
 #include <X11/Xresource.h>
 
 #include <stdio.h>
+#include <strings.h>
 
 
 bt::Resource::Resource(void)
