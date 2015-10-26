$NetBSD: patch-src_openglextensions_openglextensions.pro,v 1.1 2015/10/26 19:03:59 adam Exp $

Build shared library.

--- src/openglextensions/openglextensions.pro.orig	2015-10-26 11:22:39.000000000 +0000
+++ src/openglextensions/openglextensions.pro
@@ -1,5 +1,4 @@
 TARGET     = QtOpenGLExtensions
-CONFIG += static
 
 contains(QT_CONFIG, opengl):CONFIG += opengl
 contains(QT_CONFIG, opengles2):CONFIG += opengles2
