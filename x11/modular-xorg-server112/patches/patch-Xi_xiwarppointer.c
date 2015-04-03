$NetBSD: patch-Xi_xiwarppointer.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- Xi/xiwarppointer.c.orig	2012-05-17 17:09:01.000000000 +0000
+++ Xi/xiwarppointer.c
@@ -56,6 +56,8 @@ int
 SProcXIWarpPointer(ClientPtr client)
 {
     REQUEST(xXIWarpPointerReq);
+    REQUEST_SIZE_MATCH(xXIWarpPointerReq);
+
     swaps(&stuff->length);
     swapl(&stuff->src_win);
     swapl(&stuff->dst_win);
