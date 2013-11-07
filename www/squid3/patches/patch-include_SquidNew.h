$NetBSD: patch-include_SquidNew.h,v 1.1 2013/11/07 00:47:05 joerg Exp $

C++ says explicitly that new/delete must be global symbols.

--- include/SquidNew.h.orig	2013-11-07 00:30:31.000000000 +0000
+++ include/SquidNew.h
@@ -31,7 +31,7 @@
 #ifndef SQUID_NEW_H
 #define SQUID_NEW_H
 
-#ifndef __SUNPRO_CC
+#if 0
 /* Any code using libstdc++ must have externally resolvable overloads
  * for void * operator new - which means in the .o for the binary,
  * or in a shared library. static libs don't propogate the symbol
