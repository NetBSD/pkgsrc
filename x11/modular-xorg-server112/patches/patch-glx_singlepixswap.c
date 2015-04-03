$NetBSD: patch-glx_singlepixswap.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- glx/singlepixswap.c.orig	2012-05-17 17:09:02.000000000 +0000
+++ glx/singlepixswap.c
@@ -57,6 +57,8 @@ __glXDispSwap_ReadPixels(__GLXclientStat
     int error;
     char *answer, answerBuffer[200];
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 28);
+
     __GLX_SWAP_INT(&((xGLXSingleReq *) pc)->contextTag);
     cx = __glXForceCurrent(cl, __GLX_GET_SINGLE_CONTEXT_TAG(pc), &error);
     if (!cx) {
@@ -122,6 +124,8 @@ __glXDispSwap_GetTexImage(__GLXclientSta
     char *answer, answerBuffer[200];
     GLint width = 0, height = 0, depth = 1;
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 20);
+
     __GLX_SWAP_INT(&((xGLXSingleReq *) pc)->contextTag);
     cx = __glXForceCurrent(cl, __GLX_GET_SINGLE_CONTEXT_TAG(pc), &error);
     if (!cx) {
@@ -197,6 +201,8 @@ __glXDispSwap_GetPolygonStipple(__GLXcli
 
     __GLX_DECLARE_SWAP_VARIABLES;
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 4);
+
     __GLX_SWAP_INT(&((xGLXSingleReq *) pc)->contextTag);
     cx = __glXForceCurrent(cl, __GLX_GET_SINGLE_CONTEXT_TAG(pc), &error);
     if (!cx) {
@@ -266,15 +272,13 @@ GetSeparableFilter(__GLXclientState * cl
     compsize = __glGetTexImage_size(target, 1, format, type, width, 1, 1);
     compsize2 = __glGetTexImage_size(target, 1, format, type, height, 1, 1);
 
-    if (compsize < 0)
+    if ((compsize = safe_pad(compsize)) < 0)
         compsize = 0;
-    if (compsize2 < 0)
+    if ((compsize2 = safe_pad(compsize2)) < 0)
         compsize2 = 0;
-    compsize = __GLX_PAD(compsize);
-    compsize2 = __GLX_PAD(compsize2);
 
     CALL_PixelStorei(GET_DISPATCH(), (GL_PACK_SWAP_BYTES, !swapBytes));
-    __GLX_GET_ANSWER_BUFFER(answer, cl, compsize + compsize2, 1);
+    __GLX_GET_ANSWER_BUFFER(answer, cl, safe_add(compsize, compsize2), 1);
     __glXClearErrorOccured();
     CALL_GetSeparableFilter(GET_DISPATCH(), (*(GLenum *) (pc + 0),
                                              *(GLenum *) (pc + 4),
@@ -302,7 +306,9 @@ int
 __glXDispSwap_GetSeparableFilter(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_SINGLE_CONTEXT_TAG(pc);
+    ClientPtr client = cl->client;
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 16);
     return GetSeparableFilter(cl, pc + __GLX_SINGLE_HDR_SIZE, tag);
 }
 
@@ -310,7 +316,9 @@ int
 __glXDispSwap_GetSeparableFilterEXT(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_VENDPRIV_CONTEXT_TAG(pc);
+    ClientPtr client = cl->client;
 
+    REQUEST_FIXED_SIZE(xGLXVendorPrivateReq, 16);
     return GetSeparableFilter(cl, pc + __GLX_VENDPRIV_HDR_SIZE, tag);
 }
 
@@ -388,7 +396,9 @@ int
 __glXDispSwap_GetConvolutionFilter(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_SINGLE_CONTEXT_TAG(pc);
+    ClientPtr client = cl->client;
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 16);
     return GetConvolutionFilter(cl, pc + __GLX_SINGLE_HDR_SIZE, tag);
 }
 
@@ -396,7 +406,9 @@ int
 __glXDispSwap_GetConvolutionFilterEXT(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_VENDPRIV_CONTEXT_TAG(pc);
+    ClientPtr client = cl->client;
 
+    REQUEST_FIXED_SIZE(xGLXVendorPrivateReq, 16);
     return GetConvolutionFilter(cl, pc + __GLX_VENDPRIV_HDR_SIZE, tag);
 }
 
@@ -463,7 +475,9 @@ int
 __glXDispSwap_GetHistogram(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_SINGLE_CONTEXT_TAG(pc);
+    ClientPtr client = cl->client;
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 16);
     return GetHistogram(cl, pc + __GLX_SINGLE_HDR_SIZE, tag);
 }
 
@@ -471,7 +485,9 @@ int
 __glXDispSwap_GetHistogramEXT(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_VENDPRIV_CONTEXT_TAG(pc);
+    ClientPtr client = cl->client;
 
+    REQUEST_FIXED_SIZE(xGLXVendorPrivateReq, 16);
     return GetHistogram(cl, pc + __GLX_VENDPRIV_HDR_SIZE, tag);
 }
 
@@ -529,7 +545,9 @@ int
 __glXDispSwap_GetMinmax(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_SINGLE_CONTEXT_TAG(pc);
+    ClientPtr client = cl->client;
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 16);
     return GetMinmax(cl, pc + __GLX_SINGLE_HDR_SIZE, tag);
 }
 
@@ -537,7 +555,9 @@ int
 __glXDispSwap_GetMinmaxEXT(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_VENDPRIV_CONTEXT_TAG(pc);
+    ClientPtr client = cl->client;
 
+    REQUEST_FIXED_SIZE(xGLXVendorPrivateReq, 16);
     return GetMinmax(cl, pc + __GLX_VENDPRIV_HDR_SIZE, tag);
 }
 
@@ -605,7 +625,9 @@ int
 __glXDispSwap_GetColorTable(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_SINGLE_CONTEXT_TAG(pc);
+    ClientPtr client = cl->client;
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 16);
     return GetColorTable(cl, pc + __GLX_SINGLE_HDR_SIZE, tag);
 }
 
@@ -613,6 +635,8 @@ int
 __glXDispSwap_GetColorTableSGI(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_VENDPRIV_CONTEXT_TAG(pc);
+    ClientPtr client = cl->client;
 
+    REQUEST_FIXED_SIZE(xGLXVendorPrivateReq, 16);
     return GetColorTable(cl, pc + __GLX_VENDPRIV_HDR_SIZE, tag);
 }
