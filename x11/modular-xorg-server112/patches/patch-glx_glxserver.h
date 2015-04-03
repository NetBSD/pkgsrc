$NetBSD: patch-glx_glxserver.h,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- glx/glxserver.h.orig	2012-05-17 17:09:02.000000000 +0000
+++ glx/glxserver.h
@@ -167,7 +167,7 @@ typedef int (*__GLXprocPtr) (__GLXclient
 /*
  * Tables for computing the size of each rendering command.
  */
-typedef int (*gl_proto_size_func) (const GLbyte *, Bool);
+typedef int (*gl_proto_size_func) (const GLbyte *, Bool, int);
 
 typedef struct {
     int bytes;
@@ -218,6 +218,47 @@ extern void glxSwapQueryServerStringRepl
  * Routines for computing the size of variably-sized rendering commands.
  */
 
+static _X_INLINE int
+safe_add(int a, int b)
+{
+    if (a < 0 || b < 0)
+        return -1;
+
+    if (INT_MAX - a < b)
+        return -1;
+
+    return a + b;
+}
+
+static _X_INLINE int
+safe_mul(int a, int b)
+{
+    if (a < 0 || b < 0)
+        return -1;
+
+    if (a == 0 || b == 0)
+        return 0;
+
+    if (a > INT_MAX / b)
+        return -1;
+
+    return a * b;
+}
+
+static _X_INLINE int
+safe_pad(int a)
+{
+    int ret;
+
+    if (a < 0)
+        return -1;
+
+    if ((ret = safe_add(a, 3)) < 0)
+        return -1;
+
+    return ret & (GLuint)~3;
+}
+
 extern int __glXTypeSize(GLenum enm);
 extern int __glXImageSize(GLenum format, GLenum type,
                           GLenum target, GLsizei w, GLsizei h, GLsizei d,
