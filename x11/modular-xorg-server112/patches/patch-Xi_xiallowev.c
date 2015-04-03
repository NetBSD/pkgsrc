$NetBSD: patch-Xi_xiallowev.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- Xi/xiallowev.c.orig	2012-05-17 17:09:01.000000000 +0000
+++ Xi/xiallowev.c
@@ -48,6 +48,7 @@ int
 SProcXIAllowEvents(ClientPtr client)
 {
     REQUEST(xXIAllowEventsReq);
+    REQUEST_AT_LEAST_SIZE(xXIAllowEventsReq);
 
     swaps(&stuff->length);
     swaps(&stuff->deviceid);
@@ -55,6 +56,7 @@ SProcXIAllowEvents(ClientPtr client)
     if (stuff->length > 3) {
         xXI2_2AllowEventsReq *req_xi22 = (xXI2_2AllowEventsReq *) stuff;
 
+        REQUEST_AT_LEAST_SIZE(xXI2_2AllowEventsReq);
         swapl(&req_xi22->touchid);
         swapl(&req_xi22->grab_window);
     }
