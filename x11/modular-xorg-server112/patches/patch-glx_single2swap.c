$NetBSD: patch-glx_single2swap.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- glx/single2swap.c.orig	2012-05-17 17:09:02.000000000 +0000
+++ glx/single2swap.c
@@ -45,6 +45,7 @@
 int
 __glXDispSwap_FeedbackBuffer(__GLXclientState * cl, GLbyte * pc)
 {
+    ClientPtr client = cl->client;
     GLsizei size;
     GLenum type;
 
@@ -52,6 +53,8 @@ __glXDispSwap_FeedbackBuffer(__GLXclient
     __GLXcontext *cx;
     int error;
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 8);
+
     __GLX_SWAP_INT(&((xGLXSingleReq *) pc)->contextTag);
     cx = __glXForceCurrent(cl, __GLX_GET_SINGLE_CONTEXT_TAG(pc), &error);
     if (!cx) {
@@ -81,12 +84,15 @@ __glXDispSwap_FeedbackBuffer(__GLXclient
 int
 __glXDispSwap_SelectBuffer(__GLXclientState * cl, GLbyte * pc)
 {
+    ClientPtr client = cl->client;
     __GLXcontext *cx;
     GLsizei size;
 
     __GLX_DECLARE_SWAP_VARIABLES;
     int error;
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 4);
+
     __GLX_SWAP_INT(&((xGLXSingleReq *) pc)->contextTag);
     cx = __glXForceCurrent(cl, __GLX_GET_SINGLE_CONTEXT_TAG(pc), &error);
     if (!cx) {
@@ -113,7 +119,7 @@ __glXDispSwap_SelectBuffer(__GLXclientSt
 int
 __glXDispSwap_RenderMode(__GLXclientState * cl, GLbyte * pc)
 {
-    ClientPtr client;
+    ClientPtr client = cl->client;
     __GLXcontext *cx;
     xGLXRenderModeReply reply;
     GLint nitems = 0, retBytes = 0, retval, newModeCheck;
@@ -124,6 +130,8 @@ __glXDispSwap_RenderMode(__GLXclientStat
     __GLX_DECLARE_SWAP_ARRAY_VARIABLES;
     int error;
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 4);
+
     __GLX_SWAP_INT(&((xGLXSingleReq *) pc)->contextTag);
     cx = __glXForceCurrent(cl, __GLX_GET_SINGLE_CONTEXT_TAG(pc), &error);
     if (!cx) {
@@ -204,7 +212,6 @@ __glXDispSwap_RenderMode(__GLXclientStat
      ** selection array, as per the API for glRenderMode itself.
      */
  noChangeAllowed:;
-    client = cl->client;
     reply.length = nitems;
     reply.type = X_Reply;
     reply.sequenceNumber = client->sequence;
@@ -226,11 +233,14 @@ __glXDispSwap_RenderMode(__GLXclientStat
 int
 __glXDispSwap_Flush(__GLXclientState * cl, GLbyte * pc)
 {
+    ClientPtr client = cl->client;
     __GLXcontext *cx;
     int error;
 
     __GLX_DECLARE_SWAP_VARIABLES;
 
+    REQUEST_SIZE_MATCH(xGLXSingleReq);
+
     __GLX_SWAP_INT(&((xGLXSingleReq *) pc)->contextTag);
     cx = __glXForceCurrent(cl, __GLX_GET_SINGLE_CONTEXT_TAG(pc), &error);
     if (!cx) {
@@ -245,12 +255,14 @@ __glXDispSwap_Flush(__GLXclientState * c
 int
 __glXDispSwap_Finish(__GLXclientState * cl, GLbyte * pc)
 {
+    ClientPtr client = cl->client;
     __GLXcontext *cx;
-    ClientPtr client;
     int error;
 
     __GLX_DECLARE_SWAP_VARIABLES;
 
+    REQUEST_SIZE_MATCH(xGLXSingleReq);
+
     __GLX_SWAP_INT(&((xGLXSingleReq *) pc)->contextTag);
     cx = __glXForceCurrent(cl, __GLX_GET_SINGLE_CONTEXT_TAG(pc), &error);
     if (!cx) {
@@ -262,7 +274,6 @@ __glXDispSwap_Finish(__GLXclientState * 
     cx->hasUnflushedCommands = GL_FALSE;
 
     /* Send empty reply packet to indicate finish is finished */
-    client = cl->client;
     __GLX_BEGIN_REPLY(0);
     __GLX_PUT_RETVAL(0);
     __GLX_SWAP_REPLY_HEADER();
