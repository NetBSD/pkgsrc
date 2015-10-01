$NetBSD: patch-mi_miexpose.c,v 1.1 2015/10/01 12:55:09 tnn Exp $

http://cgit.freedesktop.org/~jeremyhu/xserver/log/?h=server-1.17-apple

--- mi/miexpose.c.orig	2015-01-17 23:42:52.000000000 +0000
+++ mi/miexpose.c
@@ -408,6 +408,7 @@ void RootlessSetPixmapOfAncestors(Window
 void RootlessStartDrawing(WindowPtr pWin);
 void RootlessDamageRegion(WindowPtr pWin, RegionPtr prgn);
 Bool IsFramedWindow(WindowPtr pWin);
+#include "../fb/fb.h"
 #endif
 
 void
@@ -437,23 +438,37 @@ miPaintWindow(WindowPtr pWin, RegionPtr 
     Bool solid = TRUE;
     DrawablePtr drawable = &pWin->drawable;
 
+#ifdef XQUARTZ_CLIP_DEBUG
+    ErrorF("START %d BS %d (pR = %ld)\n", what, pWin->backgroundState, ParentRelative);
+    ErrorF("      Rgn: %d %d %d %d\n", prgn->extents.x1, prgn->extents.y1,
+	                               prgn->extents.x2 - prgn->extents.x1,
+	                               prgn->extents.y2 - prgn->extents.y1);
+    ErrorF("      Win: %d %d (%d %d) %d %d\n", pWin->origin.x, pWin->origin.y,
+	                                       pWin->winSize.extents.x1, pWin->winSize.extents.y1,
+	                                       pWin->winSize.extents.x2 - pWin->winSize.extents.x1,
+					       pWin->winSize.extents.y2 - pWin->winSize.extents.y1);
+    ErrorF("     Draw: %d %d %d %d\n", pWin->drawable.x, pWin->drawable.y,
+				       pWin->drawable.width, pWin->drawable.height);
+#endif
+
 #ifdef ROOTLESS
     if (!drawable || drawable->type == UNDRAWABLE_WINDOW)
         return;
+#endif
 
-    if (IsFramedWindow(pWin)) {
+    if (what == PW_BACKGROUND)
+    {
+#ifdef ROOTLESS
+        if(IsFramedWindow(pWin)) {
         RootlessStartDrawing(pWin);
         RootlessDamageRegion(pWin, prgn);
 
-        if (pWin->backgroundState == ParentRelative) {
-            if ((what == PW_BACKGROUND) ||
-                (what == PW_BORDER && !pWin->borderIsPixel))
+            if(pWin->backgroundState == ParentRelative) {
                 RootlessSetPixmapOfAncestors(pWin);
         }
     }
 #endif
 
-    if (what == PW_BACKGROUND) {
         while (pWin->backgroundState == ParentRelative)
             pWin = pWin->parent;
 
@@ -478,6 +493,18 @@ miPaintWindow(WindowPtr pWin, RegionPtr 
     else {
         PixmapPtr pixmap;
 
+#ifdef ROOTLESS
+	if(IsFramedWindow(pWin)) {
+	    RootlessStartDrawing(pWin);
+	    RootlessDamageRegion(pWin, prgn);
+	    
+	    if(!pWin->borderIsPixel &&
+		pWin->backgroundState == ParentRelative) {
+		RootlessSetPixmapOfAncestors(pWin);
+	    }
+	}
+#endif
+
         tile_x_off = drawable->x;
         tile_y_off = drawable->y;
 
@@ -486,6 +513,12 @@ miPaintWindow(WindowPtr pWin, RegionPtr 
             return;
         pixmap = (*pScreen->GetWindowPixmap) ((WindowPtr) drawable);
         drawable = &pixmap->drawable;
+
+#ifdef XQUARTZ_CLIP_DEBUG
+        ErrorF("     Draw: %d %d %d %d\n",
+               drawable->x, drawable->y, drawable->width, drawable->height);    
+#endif
+	
 #ifdef COMPOSITE
         draw_x_off = pixmap->screen_x;
         draw_y_off = pixmap->screen_y;
@@ -548,6 +581,57 @@ miPaintWindow(WindowPtr pWin, RegionPtr 
     ChangeGC(NullClient, pGC, gcmask, gcval);
     ValidateGC(drawable, pGC);
 
+#ifdef XQUARTZ_CLIP_DEBUG
+    ErrorF("       GC: %d %d %d %d\n",
+	   pGC->pCompositeClip->extents.x1, pGC->pCompositeClip->extents.y1,
+	   pGC->pCompositeClip->extents.x2 - pGC->pCompositeClip->extents.x1,
+	   pGC->pCompositeClip->extents.y2 - pGC->pCompositeClip->extents.y1);
+#endif
+    
+#ifdef XQUARTZ
+    /* Looks like our clipping isn't set right for some reason:
+     * http://xquartz.macosforge.org/trac/ticket/290
+     */
+    if(what == PW_BORDER) {
+
+#if 0
+	if(solid) {
+#if 1
+	    fbFillRegionSolid(&pWin->drawable,
+			      prgn,
+			      0,
+			      fbReplicatePixel(fill.pixel,
+					       pWin->drawable.bitsPerPixel));
+#else
+	    fbFillRegionSolid(drawable,
+			      prgn,
+			      0,
+			      fbReplicatePixel(fill.pixel,
+					       drawable->bitsPerPixel));
+#endif
+	    return;
+	}
+#endif
+    
+	pGC->pCompositeClip->extents.x1 += prgn->extents.x1;
+	pGC->pCompositeClip->extents.y1 += prgn->extents.y1;
+	pGC->pCompositeClip->extents.x2 += prgn->extents.x1;
+	pGC->pCompositeClip->extents.y2 += prgn->extents.y1;
+	
+	if(pGC->pCompositeClip->extents.x2 > drawable->pScreen->width)
+	    pGC->pCompositeClip->extents.x2 = drawable->pScreen->width;
+	if(pGC->pCompositeClip->extents.y2 > drawable->pScreen->height)
+	    pGC->pCompositeClip->extents.y2 = drawable->pScreen->height;
+    }
+#endif
+
+#ifdef XQUARTZ_CLIP_DEBUG
+    ErrorF("       GC: %d %d %d %d\n",
+	   pGC->pCompositeClip->extents.x1, pGC->pCompositeClip->extents.y1,
+	   pGC->pCompositeClip->extents.x2 - pGC->pCompositeClip->extents.x1,
+	   pGC->pCompositeClip->extents.y2 - pGC->pCompositeClip->extents.y1);    
+#endif
+
     numRects = RegionNumRects(prgn);
     pbox = RegionRects(prgn);
     for (i = numRects; --i >= 0; pbox++, prect++) {
