$NetBSD: patch-tests_gtkgears.c,v 1.1 2023/01/02 12:04:53 adam Exp $

sincos() is problematic, because it is built-in GCC, gets detected by meson,
but then making docs fails.

--- tests/gtkgears.c.orig	2023-01-02 11:39:17.817427476 +0000
+++ tests/gtkgears.c
@@ -48,14 +48,12 @@
 #define VERTICES_PER_TOOTH 34
 #define GEAR_VERTEX_STRIDE 6
 
-#ifndef HAVE_SINCOS
 static void
-sincos (double x, double *_sin, double *_cos)
+my_sincos (double x, double *_sin, double *_cos)
 {
   *_sin = sin (x);
   *_cos = cos (x);
 }
-#endif
 
 /**
  * Struct describing the vertices in triangle strip
@@ -306,11 +304,11 @@ create_gear (GLfloat inner_radius,
     struct point p[7];
 
     /* Calculate needed sin/cos for varius angles */
-    sincos(i * 2.0 * G_PI / teeth + da * 0, &s[0], &c[0]);
-    sincos(i * 2.0 * M_PI / teeth + da * 1, &s[1], &c[1]);
-    sincos(i * 2.0 * M_PI / teeth + da * 2, &s[2], &c[2]);
-    sincos(i * 2.0 * M_PI / teeth + da * 3, &s[3], &c[3]);
-    sincos(i * 2.0 * M_PI / teeth + da * 4, &s[4], &c[4]);
+    my_sincos(i * 2.0 * G_PI / teeth + da * 0, &s[0], &c[0]);
+    my_sincos(i * 2.0 * M_PI / teeth + da * 1, &s[1], &c[1]);
+    my_sincos(i * 2.0 * M_PI / teeth + da * 2, &s[2], &c[2]);
+    my_sincos(i * 2.0 * M_PI / teeth + da * 3, &s[3], &c[3]);
+    my_sincos(i * 2.0 * M_PI / teeth + da * 4, &s[4], &c[4]);
 
     GEAR_POINT(p[0], r2, 1);
     GEAR_POINT(p[1], r2, 2);
@@ -519,7 +517,7 @@ void perspective(GLfloat *m, GLfloat fov
    identity(tmp);
 
    deltaZ = zFar - zNear;
-   sincos(radians, &sine, &cosine);
+   my_sincos(radians, &sine, &cosine);
 
    if ((deltaZ == 0) || (sine == 0) || (aspect == 0))
       return;
