$NetBSD: patch-glx_indirect__program.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- glx/indirect_program.c.orig	2012-05-17 17:09:02.000000000 +0000
+++ glx/indirect_program.c
@@ -69,6 +69,8 @@ DoGetProgramString(struct __GLXclientSta
     __GLXcontext *const cx = __glXForceCurrent(cl, req->contextTag, &error);
     ClientPtr client = cl->client;
 
+    REQUEST_FIXED_SIZE(xGLXVendorPrivateWithReplyReq, 8);
+
     pc += __GLX_VENDPRIV_HDR_SIZE;
     if (cx != NULL) {
         GLenum target;
