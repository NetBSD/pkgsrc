$NetBSD: patch-src_rxvtutil.h,v 1.1 2013/11/10 20:29:24 joerg Exp $

C++ requires replacements for new and delete to be global.

--- src/rxvtutil.h.orig	2013-11-09 22:04:25.000000000 +0000
+++ src/rxvtutil.h
@@ -89,19 +89,6 @@ struct rxvt_vec : simplevec<void *>
 };
 #endif
 
-inline void *
-operator new (size_t size)
-{
-  // TODO: use rxvt_malloc
-  return malloc (size);
-}
-
-inline void
-operator delete (void *p)
-{
-  free (p);
-}
-
 template<typename T>
 struct auto_ptr
 {
