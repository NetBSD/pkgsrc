$NetBSD: patch-Xext_xcmisc.c,v 1.1 2014/12/21 16:03:17 wiz Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- Xext/xcmisc.c.orig	2012-05-17 17:09:01.000000000 +0000
+++ Xext/xcmisc.c
@@ -161,6 +161,7 @@ static int
 SProcXCMiscGetXIDList(ClientPtr client)
 {
     REQUEST(xXCMiscGetXIDListReq);
+    REQUEST_SIZE_MATCH(xXCMiscGetXIDListReq);
 
     swaps(&stuff->length);
     swapl(&stuff->count);
