$NetBSD: patch-src_corelib_tools_qsharedpointer__impl.h,v 1.1 2021/07/09 22:48:47 markd Exp $

Build fixes for GCC 11

Task-number: QTBUG-89977
Change-Id: Ic1b7ddbffb8a0a00f8c621d09a868f1d94a52c21
Reviewed-by: ￼Lars Knoll <lars.knoll@qt.io>
Reviewed-by: ￼Thiago Macieira <thiago.macieira@intel.com>
(cherry picked from commit 813a928c)

--- src/corelib/tools/qsharedpointer_impl.h.orig	2020-10-27 08:02:11.000000000 +0000
+++ src/corelib/tools/qsharedpointer_impl.h
@@ -155,9 +155,6 @@ namespace QtSharedPointer {
 #endif
         inline void checkQObjectShared(...) { }
         inline void setQObjectShared(...) { }
-
-        inline void operator delete(void *ptr) { ::operator delete(ptr); }
-        inline void operator delete(void *, void *) { }
     };
     // sizeof(ExternalRefCountData) = 12 (32-bit) / 16 (64-bit)
 
