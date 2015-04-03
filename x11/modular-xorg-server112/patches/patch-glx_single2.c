$NetBSD: patch-glx_single2.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- glx/single2.c.orig	2012-05-17 17:09:02.000000000 +0000
+++ glx/single2.c
@@ -49,11 +49,14 @@
 int
 __glXDisp_FeedbackBuffer(__GLXclientState * cl, GLbyte * pc)
 {
+    ClientPtr client = cl->client;
     GLsizei size;
     GLenum type;
     __GLXcontext *cx;
     int error;
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 8);
+
     cx = __glXForceCurrent(cl, __GLX_GET_SINGLE_CONTEXT_TAG(pc), &error);
     if (!cx) {
         return error;
@@ -80,10 +83,13 @@ __glXDisp_FeedbackBuffer(__GLXclientStat
 int
 __glXDisp_SelectBuffer(__GLXclientState * cl, GLbyte * pc)
 {
+    ClientPtr client = cl->client;
     __GLXcontext *cx;
     GLsizei size;
     int error;
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 4);
+
     cx = __glXForceCurrent(cl, __GLX_GET_SINGLE_CONTEXT_TAG(pc), &error);
     if (!cx) {
         return error;
@@ -108,7 +114,7 @@ __glXDisp_SelectBuffer(__GLXclientState 
 int
 __glXDisp_RenderMode(__GLXclientState * cl, GLbyte * pc)
 {
-    ClientPtr client;
+    ClientPtr client = cl->client;
     xGLXRenderModeReply reply;
     __GLXcontext *cx;
     GLint nitems = 0, retBytes = 0, retval, newModeCheck;
@@ -116,6 +122,8 @@ __glXDisp_RenderMode(__GLXclientState * 
     GLenum newMode;
     int error;
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 4);
+
     cx = __glXForceCurrent(cl, __GLX_GET_SINGLE_CONTEXT_TAG(pc), &error);
     if (!cx) {
         return error;
@@ -192,7 +200,6 @@ __glXDisp_RenderMode(__GLXclientState * 
      ** selection array, as per the API for glRenderMode itself.
      */
  noChangeAllowed:;
-    client = cl->client;
     reply.length = nitems;
     reply.type = X_Reply;
     reply.sequenceNumber = client->sequence;
@@ -209,9 +216,12 @@ __glXDisp_RenderMode(__GLXclientState * 
 int
 __glXDisp_Flush(__GLXclientState * cl, GLbyte * pc)
 {
+    ClientPtr client = cl->client;
     __GLXcontext *cx;
     int error;
 
+    REQUEST_SIZE_MATCH(xGLXSingleReq);
+
     cx = __glXForceCurrent(cl, __GLX_GET_SINGLE_CONTEXT_TAG(pc), &error);
     if (!cx) {
         return error;
@@ -225,10 +235,12 @@ __glXDisp_Flush(__GLXclientState * cl, G
 int
 __glXDisp_Finish(__GLXclientState * cl, GLbyte * pc)
 {
+    ClientPtr client = cl->client;
     __GLXcontext *cx;
-    ClientPtr client;
     int error;
 
+    REQUEST_SIZE_MATCH(xGLXSingleReq);
+
     cx = __glXForceCurrent(cl, __GLX_GET_SINGLE_CONTEXT_TAG(pc), &error);
     if (!cx) {
         return error;
@@ -319,7 +331,7 @@ __glXcombine_strings(const char *cext_st
 int
 DoGetString(__GLXclientState * cl, GLbyte * pc, GLboolean need_swap)
 {
-    ClientPtr client;
+    ClientPtr client = cl->client;
     __GLXcontext *cx;
     GLenum name;
     const char *string;
@@ -329,6 +341,8 @@ DoGetString(__GLXclientState * cl, GLbyt
     char *buf = NULL, *buf1 = NULL;
     GLint length = 0;
 
+    REQUEST_FIXED_SIZE(xGLXSingleReq, 4);
+
     /* If the client has the opposite byte order, swap the contextTag and
      * the name.
      */
@@ -345,7 +359,6 @@ DoGetString(__GLXclientState * cl, GLbyt
     pc += __GLX_SINGLE_HDR_SIZE;
     name = *(GLenum *) (pc + 0);
     string = (const char *) CALL_GetString(GET_DISPATCH(), (name));
-    client = cl->client;
 
     if (string == NULL)
         string = "";
