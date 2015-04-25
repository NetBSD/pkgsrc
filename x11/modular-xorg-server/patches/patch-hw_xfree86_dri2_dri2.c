$NetBSD: patch-hw_xfree86_dri2_dri2.c,v 1.2 2015/04/25 11:47:03 tnn Exp $

Fix uninitialized variables warning from clang (X crashes without this)

dri2.c:242:27: note: initialize the variable 'ref' to silence this warning
    DRI2DrawableRefPtr ref;
dri2.c:320:27: note: initialize the variable 'ref' to silence this warning
    DRI2DrawableRefPtr ref, next;
dri2.c:601:27: note: initialize the variable 'ref' to silence this warning
    DRI2DrawableRefPtr ref;

--- hw/xfree86/dri2/dri2.c.orig	2015-01-26 18:42:23.000000000 +0000
+++ hw/xfree86/dri2/dri2.c
@@ -279,7 +279,7 @@ typedef struct DRI2DrawableRefRec {
 static DRI2DrawableRefPtr
 DRI2LookupDrawableRef(DRI2DrawablePtr pPriv, XID id)
 {
-    DRI2DrawableRefPtr ref;
+    DRI2DrawableRefPtr ref = NULL;
 
     xorg_list_for_each_entry(ref, &pPriv->reference_list, link) {
         if (ref->id == id)
@@ -359,7 +359,7 @@ static int
 DRI2DrawableGone(void *p, XID id)
 {
     DRI2DrawablePtr pPriv = p;
-    DRI2DrawableRefPtr ref, next;
+    DRI2DrawableRefPtr ref = NULL, next;
     WindowPtr pWin;
     PixmapPtr pPixmap;
     DrawablePtr pDraw;
@@ -676,7 +676,7 @@ static void
 DRI2InvalidateDrawable(DrawablePtr pDraw)
 {
     DRI2DrawablePtr pPriv = DRI2GetDrawable(pDraw);
-    DRI2DrawableRefPtr ref;
+    DRI2DrawableRefPtr ref = NULL;
 
     if (!pPriv || !pPriv->needInvalidate)
         return;
