$NetBSD: patch-Xi_xiquerypointer.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- Xi/xiquerypointer.c.orig	2012-05-17 17:09:01.000000000 +0000
+++ Xi/xiquerypointer.c
@@ -62,6 +62,8 @@ int
 SProcXIQueryPointer(ClientPtr client)
 {
     REQUEST(xXIQueryPointerReq);
+    REQUEST_SIZE_MATCH(xXIQueryPointerReq);
+
     swaps(&stuff->length);
     swaps(&stuff->deviceid);
     swapl(&stuff->win);
