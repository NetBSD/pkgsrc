$NetBSD: patch-glx_rensize.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- glx/rensize.c.orig	2012-05-17 17:09:02.000000000 +0000
+++ glx/rensize.c
@@ -52,7 +52,7 @@ Map1Size(GLint k, GLint order)
 }
 
 int
-__glXMap1dReqSize(const GLbyte * pc, Bool swap)
+__glXMap1dReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLenum target;
     GLint order, k;
@@ -68,7 +68,7 @@ __glXMap1dReqSize(const GLbyte * pc, Boo
 }
 
 int
-__glXMap1fReqSize(const GLbyte * pc, Bool swap)
+__glXMap1fReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLenum target;
     GLint order, k;
@@ -92,7 +92,7 @@ Map2Size(int k, int majorOrder, int mino
 }
 
 int
-__glXMap2dReqSize(const GLbyte * pc, Bool swap)
+__glXMap2dReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLenum target;
     GLint uorder, vorder, k;
@@ -110,7 +110,7 @@ __glXMap2dReqSize(const GLbyte * pc, Boo
 }
 
 int
-__glXMap2fReqSize(const GLbyte * pc, Bool swap)
+__glXMap2fReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLenum target;
     GLint uorder, vorder, k;
@@ -342,13 +342,14 @@ __glXTypeSize(GLenum enm)
 }
 
 int
-__glXDrawArraysReqSize(const GLbyte * pc, Bool swap)
+__glXDrawArraysReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     __GLXdispatchDrawArraysHeader *hdr = (__GLXdispatchDrawArraysHeader *) pc;
     __GLXdispatchDrawArraysComponentHeader *compHeader;
     GLint numVertexes = hdr->numVertexes;
     GLint numComponents = hdr->numComponents;
     GLint arrayElementSize = 0;
+    GLint x, size;
     int i;
 
     if (swap) {
@@ -357,6 +358,13 @@ __glXDrawArraysReqSize(const GLbyte * pc
     }
 
     pc += sizeof(__GLXdispatchDrawArraysHeader);
+    reqlen -= sizeof(__GLXdispatchDrawArraysHeader);
+
+    size = safe_mul(sizeof(__GLXdispatchDrawArraysComponentHeader),
+                    numComponents);
+    if (size < 0 || reqlen < 0 || reqlen < size)
+        return -1;
+
     compHeader = (__GLXdispatchDrawArraysComponentHeader *) pc;
 
     for (i = 0; i < numComponents; i++) {
@@ -400,17 +408,18 @@ __glXDrawArraysReqSize(const GLbyte * pc
             return -1;
         }
 
-        arrayElementSize += __GLX_PAD(numVals * __glXTypeSize(datatype));
+        x = safe_pad(safe_mul(numVals, __glXTypeSize(datatype)));
+        if ((arrayElementSize = safe_add(arrayElementSize, x)) < 0)
+            return -1;
 
         pc += sizeof(__GLXdispatchDrawArraysComponentHeader);
     }
 
-    return ((numComponents * sizeof(__GLXdispatchDrawArraysComponentHeader)) +
-            (numVertexes * arrayElementSize));
+    return safe_add(size, safe_mul(numVertexes, arrayElementSize));
 }
 
 int
-__glXSeparableFilter2DReqSize(const GLbyte * pc, Bool swap)
+__glXSeparableFilter2DReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     __GLXdispatchConvolutionFilterHeader *hdr =
         (__GLXdispatchConvolutionFilterHeader *) pc;
