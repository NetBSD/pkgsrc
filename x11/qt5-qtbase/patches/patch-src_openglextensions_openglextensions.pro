$NetBSD: patch-src_openglextensions_openglextensions.pro,v 1.2 2018/01/17 19:30:47 markd Exp $

Build shared library.

--- src/openglextensions/openglextensions.pro.orig	2017-01-18 14:20:58.000000000 +0000
+++ src/openglextensions/openglextensions.pro
@@ -1,5 +1,4 @@
 TARGET     = QtOpenGLExtensions
-CONFIG += static
 
 qtConfig(opengl): CONFIG += opengl
 qtConfig(opengles2): CONFIG += opengles2
