$NetBSD: patch-hw_xfree86_dri2_dri2ext.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- hw/xfree86/dri2/dri2ext.c.orig	2012-05-17 17:09:03.000000000 +0000
+++ hw/xfree86/dri2/dri2ext.c
@@ -263,6 +263,9 @@ ProcDRI2GetBuffers(ClientPtr client)
     unsigned int *attachments;
 
     REQUEST_FIXED_SIZE(xDRI2GetBuffersReq, stuff->count * 4);
+    if (stuff->count > (INT_MAX / 4))
+        return BadLength;
+
     if (!validDrawable(client, stuff->drawable, DixReadAccess | DixWriteAccess,
                        &pDrawable, &status))
         return status;
