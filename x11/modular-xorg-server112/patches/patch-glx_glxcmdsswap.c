$NetBSD: patch-glx_glxcmdsswap.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- glx/glxcmdsswap.c.orig	2012-05-17 17:09:02.000000000 +0000
+++ glx/glxcmdsswap.c
@@ -962,11 +962,13 @@ __glXDispSwap_RenderLarge(__GLXclientSta
 int
 __glXDispSwap_VendorPrivate(__GLXclientState * cl, GLbyte * pc)
 {
+    ClientPtr client = cl->client;
     xGLXVendorPrivateReq *req;
     GLint vendorcode;
     __GLXdispatchVendorPrivProcPtr proc;
 
     __GLX_DECLARE_SWAP_VARIABLES;
+    REQUEST_AT_LEAST_SIZE(xGLXVendorPrivateReq);
 
     req = (xGLXVendorPrivateReq *) pc;
     __GLX_SWAP_SHORT(&req->length);
@@ -989,11 +991,13 @@ __glXDispSwap_VendorPrivate(__GLXclientS
 int
 __glXDispSwap_VendorPrivateWithReply(__GLXclientState * cl, GLbyte * pc)
 {
+    ClientPtr client = cl->client;
     xGLXVendorPrivateWithReplyReq *req;
     GLint vendorcode;
     __GLXdispatchVendorPrivProcPtr proc;
 
     __GLX_DECLARE_SWAP_VARIABLES;
+    REQUEST_AT_LEAST_SIZE(xGLXVendorPrivateWithReplyReq);
 
     req = (xGLXVendorPrivateWithReplyReq *) pc;
     __GLX_SWAP_SHORT(&req->length);
