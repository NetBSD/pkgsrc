$NetBSD: patch-src_FbTk_TextureRender.cc,v 1.1 2011/11/25 22:25:31 joerg Exp $

--- src/FbTk/TextureRender.cc.orig	2011-11-25 17:39:41.000000000 +0000
+++ src/FbTk/TextureRender.cc
@@ -32,6 +32,7 @@
 #include "GContext.hh"
 
 #include <iostream>
+#include <cstring>
 #include <string>
 #ifdef HAVE_CSTDIO
   #include <cstdio>
