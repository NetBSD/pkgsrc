$NetBSD: patch-src_GCCache.cc,v 1.1 2013/04/29 21:31:13 joerg Exp $

--- src/GCCache.cc.orig	2013-04-29 20:12:40.000000000 +0000
+++ src/GCCache.cc
@@ -27,6 +27,7 @@
 
 extern "C" {
 #include <stdio.h>
+#include <stdlib.h>
 }
 
 #include "GCCache.hh"
