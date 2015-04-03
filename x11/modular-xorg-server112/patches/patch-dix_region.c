$NetBSD: patch-dix_region.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- dix/region.c.orig	2012-05-17 17:09:02.000000000 +0000
+++ dix/region.c
@@ -169,7 +169,6 @@ Equipment Corporation.
         ((r1)->y1 <= (r2)->y1) && \
         ((r1)->y2 >= (r2)->y2) )
 
-#define xallocData(n) malloc(RegionSizeof(n))
 #define xfreeData(reg) if ((reg)->data && (reg)->data->size) free((reg)->data)
 
 #define RECTALLOC_BAIL(pReg,n,bail) \
@@ -205,8 +204,9 @@ if (!(pReg)->data || (((pReg)->data->num
 #define DOWNSIZE(reg,numRects)						 \
 if (((numRects) < ((reg)->data->size >> 1)) && ((reg)->data->size > 50)) \
 {									 \
-    RegDataPtr NewData;							 \
-    NewData = (RegDataPtr)realloc((reg)->data, RegionSizeof(numRects));	 \
+    size_t NewSize = RegionSizeof(numRects);				 \
+    RegDataPtr NewData =						 \
+        (NewSize > 0) ? realloc((reg)->data, NewSize) : NULL ;		 \
     if (NewData)							 \
     {									 \
 	NewData->size = (numRects);					 \
@@ -330,17 +330,20 @@ Bool
 RegionRectAlloc(RegionPtr pRgn, int n)
 {
     RegDataPtr data;
+    size_t rgnSize;
 
     if (!pRgn->data) {
         n++;
-        pRgn->data = xallocData(n);
+        rgnSize = RegionSizeof(n);
+        pRgn->data = (rgnSize > 0) ? malloc(rgnSize) : NULL;
         if (!pRgn->data)
             return RegionBreak(pRgn);
         pRgn->data->numRects = 1;
         *RegionBoxptr(pRgn) = pRgn->extents;
     }
     else if (!pRgn->data->size) {
-        pRgn->data = xallocData(n);
+        rgnSize = RegionSizeof(n);
+        pRgn->data = (rgnSize > 0) ? malloc(rgnSize) : NULL;
         if (!pRgn->data)
             return RegionBreak(pRgn);
         pRgn->data->numRects = 0;
@@ -352,7 +355,8 @@ RegionRectAlloc(RegionPtr pRgn, int n)
                 n = 250;
         }
         n += pRgn->data->numRects;
-        data = (RegDataPtr) realloc(pRgn->data, RegionSizeof(n));
+        rgnSize = RegionSizeof(n);
+        data = (rgnSize > 0) ? realloc(pRgn->data, rgnSize) : NULL;
         if (!data)
             return RegionBreak(pRgn);
         pRgn->data = data;
@@ -1297,6 +1301,7 @@ RegionFromRects(int nrects, xRectangle *
 {
 
     RegionPtr pRgn;
+    size_t rgnSize;
     RegDataPtr pData;
     BoxPtr pBox;
     int i;
@@ -1323,7 +1328,8 @@ RegionFromRects(int nrects, xRectangle *
         }
         return pRgn;
     }
-    pData = xallocData(nrects);
+    rgnSize = RegionSizeof(nrects);
+    pData = (rgnSize > 0) ? malloc(rgnSize) : NULL;
     if (!pData) {
         RegionBreak(pRgn);
         return pRgn;
