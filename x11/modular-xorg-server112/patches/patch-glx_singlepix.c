$NetBSD: patch-glx_singlepix.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- glx/singlepix.c.orig	2012-05-17 17:09:02.000000000 +0000
+++ glx/singlepix.c
@@ -55,6 +55,8 @@ __glXDisp_ReadPixels(__GLXclientState * 
     int error;
     char *answer, answerBuffer[200];
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 28);
+
     cx = __glXForceCurrent(cl, __GLX_GET_SINGLE_CONTEXT_TAG(pc), &error);
     if (!cx) {
         return error;
@@ -68,7 +70,7 @@ __glXDisp_ReadPixels(__GLXclientState * 
     swapBytes = *(GLboolean *) (pc + 24);
     lsbFirst = *(GLboolean *) (pc + 25);
     compsize = __glReadPixels_size(format, type, width, height);
-    if (compsize < 0)
+    if ((compsize = safe_pad(compsize)) < 0)
         compsize = 0;
 
     CALL_PixelStorei(GET_DISPATCH(), (GL_PACK_SWAP_BYTES, swapBytes));
@@ -107,6 +109,8 @@ __glXDisp_GetTexImage(__GLXclientState *
     char *answer, answerBuffer[200];
     GLint width = 0, height = 0, depth = 1;
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 20);
+
     cx = __glXForceCurrent(cl, __GLX_GET_SINGLE_CONTEXT_TAG(pc), &error);
     if (!cx) {
         return error;
@@ -133,7 +137,7 @@ __glXDisp_GetTexImage(__GLXclientState *
      */
     compsize =
         __glGetTexImage_size(target, level, format, type, width, height, depth);
-    if (compsize < 0)
+    if ((compsize = safe_pad(compsize)) < 0)
         compsize = 0;
 
     CALL_PixelStorei(GET_DISPATCH(), (GL_PACK_SWAP_BYTES, swapBytes));
@@ -169,6 +173,8 @@ __glXDisp_GetPolygonStipple(__GLXclientS
     GLubyte answerBuffer[200];
     char *answer;
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 4);
+
     cx = __glXForceCurrent(cl, __GLX_GET_SINGLE_CONTEXT_TAG(pc), &error);
     if (!cx) {
         return error;
@@ -231,15 +237,13 @@ GetSeparableFilter(__GLXclientState * cl
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
 
     CALL_PixelStorei(GET_DISPATCH(), (GL_PACK_SWAP_BYTES, swapBytes));
-    __GLX_GET_ANSWER_BUFFER(answer, cl, compsize + compsize2, 1);
+    __GLX_GET_ANSWER_BUFFER(answer, cl, safe_add(compsize, compsize2), 1);
     __glXClearErrorOccured();
     CALL_GetSeparableFilter(GET_DISPATCH(), (*(GLenum *) (pc + 0),
                                              *(GLenum *) (pc + 4),
@@ -265,7 +269,8 @@ int
 __glXDisp_GetSeparableFilter(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_SINGLE_CONTEXT_TAG(pc);
-
+    ClientPtr client = cl->client;
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 16);
     return GetSeparableFilter(cl, pc + __GLX_SINGLE_HDR_SIZE, tag);
 }
 
@@ -273,7 +278,8 @@ int
 __glXDisp_GetSeparableFilterEXT(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_VENDPRIV_CONTEXT_TAG(pc);
-
+    ClientPtr client = cl->client;
+    REQUEST_FIXED_SIZE(xGLXVendorPrivateReq, 16);
     return GetSeparableFilter(cl, pc + __GLX_VENDPRIV_HDR_SIZE, tag);
 }
 
@@ -343,7 +349,8 @@ int
 __glXDisp_GetConvolutionFilter(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_SINGLE_CONTEXT_TAG(pc);
-
+    ClientPtr client = cl->client;
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 16);
     return GetConvolutionFilter(cl, pc + __GLX_SINGLE_HDR_SIZE, tag);
 }
 
@@ -351,7 +358,8 @@ int
 __glXDisp_GetConvolutionFilterEXT(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_VENDPRIV_CONTEXT_TAG(pc);
-
+    ClientPtr client = cl->client;
+    REQUEST_FIXED_SIZE(xGLXVendorPrivateReq, 16);
     return GetConvolutionFilter(cl, pc + __GLX_VENDPRIV_HDR_SIZE, tag);
 }
 
@@ -411,7 +419,8 @@ int
 __glXDisp_GetHistogram(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_SINGLE_CONTEXT_TAG(pc);
-
+    ClientPtr client = cl->client;
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 16);
     return GetHistogram(cl, pc + __GLX_SINGLE_HDR_SIZE, tag);
 }
 
@@ -419,7 +428,8 @@ int
 __glXDisp_GetHistogramEXT(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_VENDPRIV_CONTEXT_TAG(pc);
-
+    ClientPtr client = cl->client;
+    REQUEST_FIXED_SIZE(xGLXVendorPrivateReq, 16);
     return GetHistogram(cl, pc + __GLX_VENDPRIV_HDR_SIZE, tag);
 }
 
@@ -471,7 +481,8 @@ int
 __glXDisp_GetMinmax(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_SINGLE_CONTEXT_TAG(pc);
-
+    ClientPtr client = cl->client;
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 16);
     return GetMinmax(cl, pc + __GLX_SINGLE_HDR_SIZE, tag);
 }
 
@@ -479,7 +490,8 @@ int
 __glXDisp_GetMinmaxEXT(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_VENDPRIV_CONTEXT_TAG(pc);
-
+    ClientPtr client = cl->client;
+    REQUEST_FIXED_SIZE(xGLXVendorPrivateReq, 16);
     return GetMinmax(cl, pc + __GLX_VENDPRIV_HDR_SIZE, tag);
 }
 
@@ -540,7 +552,8 @@ int
 __glXDisp_GetColorTable(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_SINGLE_CONTEXT_TAG(pc);
-
+    ClientPtr client = cl->client;
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 16);
     return GetColorTable(cl, pc + __GLX_SINGLE_HDR_SIZE, tag);
 }
 
@@ -548,6 +561,7 @@ int
 __glXDisp_GetColorTableSGI(__GLXclientState * cl, GLbyte * pc)
 {
     const GLXContextTag tag = __GLX_GET_VENDPRIV_CONTEXT_TAG(pc);
-
+    ClientPtr client = cl->client;
+    REQUEST_FIXED_SIZE(xGLXVendorPrivateReq, 16);
     return GetColorTable(cl, pc + __GLX_VENDPRIV_HDR_SIZE, tag);
 }
