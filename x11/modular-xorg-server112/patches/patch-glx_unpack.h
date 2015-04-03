$NetBSD: patch-glx_unpack.h,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- glx/unpack.h.orig	2012-05-17 17:09:02.000000000 +0000
+++ glx/unpack.h
@@ -83,7 +83,8 @@ extern xGLXSingleReply __glXReply;
 ** pointer.
 */
 #define __GLX_GET_ANSWER_BUFFER(res,cl,size,align)			 \
-    if ((size) > sizeof(answerBuffer)) {				 \
+    if (size < 0) return BadLength;                                      \
+    else if ((size) > sizeof(answerBuffer)) {				 \
 	int bump;							 \
 	if ((cl)->returnBufSize < (size)+(align)) {			 \
 	    (cl)->returnBuf = (GLbyte*)realloc((cl)->returnBuf,	 	 \
