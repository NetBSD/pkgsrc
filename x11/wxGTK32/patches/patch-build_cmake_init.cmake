$NetBSD: patch-build_cmake_init.cmake,v 1.2 2022/07/29 18:36:06 wiz Exp $

fix OpenGL detection
https://github.com/wxWidgets/wxWidgets/issues/22649
Patch from
https://github.com/wxWidgets/wxWidgets/pull/22677/

--- build/cmake/init.cmake.orig	2022-07-29 18:21:12.340086310 +0000
+++ build/cmake/init.cmake
@@ -409,8 +409,18 @@ if(wxUSE_GUI)
             set(OPENGL_LIBRARIES "-framework OpenGLES" "-framework QuartzCore" "-framework GLKit")
         else()
             find_package(OpenGL)
+            if(OPENGL_FOUND)
+                foreach(gltarget OpenGL::GL OpenGL::GLU OpenGL::OpenGL)
+                    if(TARGET ${gltarget})
+                        set(OPENGL_LIBRARIES ${gltarget} ${OPENGL_LIBRARIES})
+                    endif()
+                endforeach()
+            endif()
             if(WXGTK3 AND OpenGL_EGL_FOUND AND wxUSE_GLCANVAS_EGL)
-                set(OPENGL_LIBRARIES OpenGL::OpenGL OpenGL::GLU OpenGL::EGL)
+                if(TARGET OpenGL::EGL)
+                    set(OPENGL_LIBRARIES OpenGL::EGL ${OPENGL_LIBRARIES})
+                endif()
+                set(OPENGL_INCLUDE_DIR ${OPENGL_INCLUDE_DIR} ${OPENGL_EGL_INCLUDE_DIRS})
                 find_package(WAYLANDEGL)
                 if(WAYLANDEGL_FOUND AND wxHAVE_GDK_WAYLAND)
                     list(APPEND OPENGL_LIBRARIES ${WAYLANDEGL_LIBRARIES})
