$NetBSD: patch-src_yarray.h,v 1.1 2012/11/16 20:07:48 joerg Exp $

--- src/yarray.h.orig	2012-11-16 19:20:22.000000000 +0000
+++ src/yarray.h
@@ -150,7 +150,7 @@ public:
     }
 
     virtual void remove(const typename YArray<DataType *>::SizeType index) {
-        if (index < YArray<DataType *>::getCount()) delete getItem(index);
+        if (index < YArray<DataType *>::getCount()) delete this->getItem(index);
         YArray<DataType *>::remove(index);
     }
     
