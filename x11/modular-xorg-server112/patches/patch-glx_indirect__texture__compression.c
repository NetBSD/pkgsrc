$NetBSD: patch-glx_indirect__texture__compression.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- glx/indirect_texture_compression.c.orig	2012-05-17 17:09:02.000000000 +0000
+++ glx/indirect_texture_compression.c
@@ -47,6 +47,8 @@ __glXDisp_GetCompressedTexImageARB(struc
     __GLXcontext *const cx = __glXForceCurrent(cl, req->contextTag, &error);
     ClientPtr client = cl->client;
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 8);
+
     pc += __GLX_SINGLE_HDR_SIZE;
     if (cx != NULL) {
         const GLenum target = *(GLenum *) (pc + 0);
@@ -93,6 +95,8 @@ __glXDispSwap_GetCompressedTexImageARB(s
         __glXForceCurrent(cl, bswap_32(req->contextTag), &error);
     ClientPtr client = cl->client;
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 8);
+
     pc += __GLX_SINGLE_HDR_SIZE;
     if (cx != NULL) {
         const GLenum target = (GLenum) bswap_32(*(int *) (pc + 0));
