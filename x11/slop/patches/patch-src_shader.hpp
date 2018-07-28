$NetBSD: patch-src_shader.hpp,v 1.1 2018/07/28 15:19:59 nia Exp $

Don't introduce an unneeded dependency on egl support.

--- src/shader.hpp.orig	2018-04-23 07:56:02.000000000 +0000
+++ src/shader.hpp
@@ -29,7 +29,6 @@
 #include <GL/glew.h>
 #include <glm/glm.hpp>
 #include <glm/gtc/type_ptr.hpp>
-#include <EGL/egl.h>
 #include <GL/gl.h>
 
 #include "resource.hpp"
