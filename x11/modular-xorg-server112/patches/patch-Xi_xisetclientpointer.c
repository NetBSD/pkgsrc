$NetBSD: patch-Xi_xisetclientpointer.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- Xi/xisetclientpointer.c.orig	2012-05-17 17:09:01.000000000 +0000
+++ Xi/xisetclientpointer.c
@@ -51,10 +51,11 @@ int
 SProcXISetClientPointer(ClientPtr client)
 {
     REQUEST(xXISetClientPointerReq);
+    REQUEST_SIZE_MATCH(xXISetClientPointerReq);
+
     swaps(&stuff->length);
     swapl(&stuff->win);
     swaps(&stuff->deviceid);
-    REQUEST_SIZE_MATCH(xXISetClientPointerReq);
     return (ProcXISetClientPointer(client));
 }
 
