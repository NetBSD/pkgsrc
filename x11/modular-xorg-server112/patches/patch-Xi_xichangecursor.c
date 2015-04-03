$NetBSD: patch-Xi_xichangecursor.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- Xi/xichangecursor.c.orig	2012-05-17 17:09:01.000000000 +0000
+++ Xi/xichangecursor.c
@@ -57,11 +57,11 @@ int
 SProcXIChangeCursor(ClientPtr client)
 {
     REQUEST(xXIChangeCursorReq);
+    REQUEST_SIZE_MATCH(xXIChangeCursorReq);
     swaps(&stuff->length);
     swapl(&stuff->win);
     swapl(&stuff->cursor);
     swaps(&stuff->deviceid);
-    REQUEST_SIZE_MATCH(xXIChangeCursorReq);
     return (ProcXIChangeCursor(client));
 }
 
