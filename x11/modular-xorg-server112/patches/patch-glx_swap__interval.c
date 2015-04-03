$NetBSD: patch-glx_swap__interval.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- glx/swap_interval.c.orig	2012-05-17 17:09:02.000000000 +0000
+++ glx/swap_interval.c
@@ -50,6 +50,8 @@ DoSwapInterval(__GLXclientState * cl, GL
     __GLXcontext *cx;
     GLint interval;
 
+    REQUEST_FIXED_SIZE(xGLXVendorPrivateReq, 4);
+
     cx = __glXLookupContextByTag(cl, tag);
 
     if ((cx == NULL) || (cx->pGlxScreen == NULL)) {
