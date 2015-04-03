$NetBSD: patch-Xi_xiselectev.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- Xi/xiselectev.c.orig	2012-05-17 17:09:01.000000000 +0000
+++ Xi/xiselectev.c
@@ -63,6 +63,7 @@ int
 SProcXISelectEvents(ClientPtr client)
 {
     int i;
+    int len;
     xXIEventMask *evmask;
 
     REQUEST(xXISelectEventsReq);
@@ -71,10 +72,17 @@ SProcXISelectEvents(ClientPtr client)
     swapl(&stuff->win);
     swaps(&stuff->num_masks);
 
+    len = stuff->length - bytes_to_int32(sizeof(xXISelectEventsReq));
     evmask = (xXIEventMask *) &stuff[1];
     for (i = 0; i < stuff->num_masks; i++) {
+        if (len < bytes_to_int32(sizeof(xXIEventMask)))
+            return BadLength;
+        len -= bytes_to_int32(sizeof(xXIEventMask));
         swaps(&evmask->deviceid);
         swaps(&evmask->mask_len);
+        if (len < evmask->mask_len)
+            return BadLength;
+        len -= evmask->mask_len;
         evmask =
             (xXIEventMask *) (((char *) &evmask[1]) + evmask->mask_len * 4);
     }
