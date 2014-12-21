$NetBSD: patch-Xi_xiquerydevice.c,v 1.1 2014/12/21 16:03:17 wiz Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- Xi/xiquerydevice.c.orig	2012-07-24 04:36:54.000000000 +0000
+++ Xi/xiquerydevice.c
@@ -54,6 +54,7 @@ int
 SProcXIQueryDevice(ClientPtr client)
 {
     REQUEST(xXIQueryDeviceReq);
+    REQUEST_SIZE_MATCH(xXIQueryDeviceReq);
 
     swaps(&stuff->length);
     swaps(&stuff->deviceid);
