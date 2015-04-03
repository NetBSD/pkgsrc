$NetBSD: patch-Xi_xigetclientpointer.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- Xi/xigetclientpointer.c.orig	2012-05-17 17:09:01.000000000 +0000
+++ Xi/xigetclientpointer.c
@@ -50,6 +50,7 @@ int
 SProcXIGetClientPointer(ClientPtr client)
 {
     REQUEST(xXIGetClientPointerReq);
+    REQUEST_SIZE_MATCH(xXIGetClientPointerReq);
 
     swaps(&stuff->length);
     swapl(&stuff->win);
