$NetBSD: patch-dix_dispatch.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- dix/dispatch.c.orig	2012-05-17 17:09:01.000000000 +0000
+++ dix/dispatch.c
@@ -1952,6 +1952,9 @@ ProcPutImage(ClientPtr client)
     tmpImage = (char *) &stuff[1];
     lengthProto = length;
 
+    if (lengthProto >= (INT32_MAX / stuff->height))
+        return BadLength;
+
     if ((bytes_to_int32(lengthProto * stuff->height) +
          bytes_to_int32(sizeof(xPutImageReq))) != client->req_len)
         return BadLength;
