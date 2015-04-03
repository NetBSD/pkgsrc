$NetBSD: patch-include_regionstr.h,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- include/regionstr.h.orig	2012-05-17 17:09:04.000000000 +0000
+++ include/regionstr.h
@@ -127,7 +127,10 @@ RegionEnd(RegionPtr reg)
 static inline size_t
 RegionSizeof(int n)
 {
-    return (sizeof(RegDataRec) + ((n) * sizeof(BoxRec)));
+    if (n < ((INT_MAX - sizeof(RegDataRec)) / sizeof(BoxRec)))
+        return (sizeof(RegDataRec) + ((n) * sizeof(BoxRec)));
+    else
+        return 0;
 }
 
 static inline void
@@ -138,9 +141,10 @@ RegionInit(RegionPtr _pReg, BoxPtr _rect
         (_pReg)->data = (RegDataPtr) NULL;
     }
     else {
+        size_t rgnSize;
         (_pReg)->extents = RegionEmptyBox;
-        if (((_size) > 1) && ((_pReg)->data =
-                              (RegDataPtr) malloc(RegionSizeof(_size)))) {
+        if (((_size) > 1) && ((rgnSize = RegionSizeof(_size)) > 0) &&
+            (((_pReg)->data = malloc(rgnSize)) != NULL)) {
             (_pReg)->data->size = (_size);
             (_pReg)->data->numRects = 0;
         }
