$NetBSD: patch-Xi_xigrabdev.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- Xi/xigrabdev.c.orig	2012-05-17 17:09:01.000000000 +0000
+++ Xi/xigrabdev.c
@@ -47,6 +47,11 @@ int
 SProcXIGrabDevice(ClientPtr client)
 {
     REQUEST(xXIGrabDeviceReq);
+    /*
+     * Check here for at least the length of the struct we swap, then
+     * let ProcXIGrabDevice check the full size after we swap mask_len.
+     */
+    REQUEST_AT_LEAST_SIZE(xXIGrabDeviceReq);
 
     swaps(&stuff->length);
     swaps(&stuff->deviceid);
@@ -69,7 +74,7 @@ ProcXIGrabDevice(ClientPtr client)
     int mask_len;
 
     REQUEST(xXIGrabDeviceReq);
-    REQUEST_AT_LEAST_SIZE(xXIGrabDeviceReq);
+    REQUEST_FIXED_SIZE(xXIGrabDeviceReq, ((size_t) stuff->mask_len) * 4);
 
     ret = dixLookupDevice(&dev, stuff->deviceid, client, DixGrabAccess);
     if (ret != Success)
@@ -118,6 +123,7 @@ int
 SProcXIUngrabDevice(ClientPtr client)
 {
     REQUEST(xXIUngrabDeviceReq);
+    REQUEST_SIZE_MATCH(xXIUngrabDeviceReq);
 
     swaps(&stuff->length);
     swaps(&stuff->deviceid);
@@ -135,6 +141,7 @@ ProcXIUngrabDevice(ClientPtr client)
     TimeStamp time;
 
     REQUEST(xXIUngrabDeviceReq);
+    REQUEST_SIZE_MATCH(xXIUngrabDeviceReq);
 
     ret = dixLookupDevice(&dev, stuff->deviceid, client, DixGetAttrAccess);
     if (ret != Success)
