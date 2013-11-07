$NetBSD: patch-src_SquidNew.cc,v 1.1 2013/11/07 00:47:05 joerg Exp $

C++ says explicitly that new/delete must be global symbols.
This shouldn't be necessary, but who knows what this code is doing.

--- src/SquidNew.cc.orig	2013-11-07 00:31:58.000000000 +0000
+++ src/SquidNew.cc
@@ -35,7 +35,7 @@
 
 #include "squid.h"
 
-#ifdef __SUNPRO_CC
+#if 1
 
 #include <new>
 void *operator new(size_t size) throw (std::bad_alloc)
