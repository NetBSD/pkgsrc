$NetBSD: patch-glx_glxcmds.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- glx/glxcmds.c.orig	2012-08-02 00:59:23.000000000 +0000
+++ glx/glxcmds.c
@@ -1983,7 +1983,8 @@ __glXDisp_Render(__GLXclientState * cl, 
         if (entry.varsize) {
             /* variable size command */
             extra = (*entry.varsize) (pc + __GLX_RENDER_HDR_SIZE,
-                                      client->swapped);
+                                      client->swapped,
+                                      left - __GLX_RENDER_HDR_SIZE);
             if (extra < 0) {
                 extra = 0;
             }
@@ -2060,6 +2061,7 @@ __glXDisp_RenderLarge(__GLXclientState *
         return BadLength;
     }
     pc += sz_xGLXRenderLargeReq;
+        int left = (req->length << 2) - sz_xGLXRenderLargeReq;
 
     if (cl->largeCmdRequestsSoFar == 0) {
         __GLXrenderSizeData entry;
@@ -2100,7 +2102,8 @@ __glXDisp_RenderLarge(__GLXclientState *
              ** will be in the 1st request, so it's okay to do this.
              */
             extra = (*entry.varsize) (pc + __GLX_RENDER_LARGE_HDR_SIZE,
-                                      client->swapped);
+                                      client->swapped,
+                                      left - __GLX_RENDER_LARGE_HDR_SIZE);
             if (extra < 0) {
                 extra = 0;
             }
@@ -2178,17 +2181,16 @@ __glXDisp_RenderLarge(__GLXclientState *
              ** This is the last request; it must have enough bytes to complete
              ** the command.
              */
-            /* NOTE: the two pad macros have been added below; they are needed
-             ** because the client library pads the total byte count, but not
-             ** the per-request byte counts.  The Protocol Encoding says the
-             ** total byte count should not be padded, so a proposal will be 
-             ** made to the ARB to relax the padding constraint on the total 
-             ** byte count, thus preserving backward compatibility.  Meanwhile, 
-             ** the padding done below fixes a bug that did not allow
-             ** large commands of odd sizes to be accepted by the server.
+            /* NOTE: the pad macro below is needed because the client library
+             ** pads the total byte count, but not the per-request byte counts.
+             ** The Protocol Encoding says the total byte count should not be
+             ** padded, so a proposal will be made to the ARB to relax the
+             ** padding constraint on the total byte count, thus preserving
+             ** backward compatibility.  Meanwhile, the padding done below
+             ** fixes a bug that did not allow large commands of odd sizes to
+             ** be accepted by the server.
              */
-            if (__GLX_PAD(cl->largeCmdBytesSoFar) !=
-                __GLX_PAD(cl->largeCmdBytesTotal)) {
+            if (safe_pad(cl->largeCmdBytesSoFar) != cl->largeCmdBytesTotal) {
                 client->errorValue = dataBytes;
                 __glXResetLargeCommandStatus(cl);
                 return __glXError(GLXBadLargeRequest);
