$NetBSD: patch-platform_toolkit_xre_glxtest.cpp,v 1.2 2024/08/06 20:58:11 nia Exp $

- We are not building with Gtk+3.  Doing this dlopen() causes a SIGTRAP
  in NetBSD libc in _rtld_unref_dag.
- NetBSD does not have the libGL.so.1 version.

--- platform/toolkit/xre/glxtest.cpp.orig	2024-07-10 08:54:53.000000000 +0000
+++ platform/toolkit/xre/glxtest.cpp
@@ -127,7 +127,7 @@ void glxtest()
     dup2(fd, i);
   close(fd);
 
-#if MOZ_WIDGET_GTK == 2
+#if 0
   // On Gtk+2 builds, try to get the Gtk+3 version if it's installed, and
   // use that in nsSystemInfo for secondaryLibrary. Better safe than sorry,
   // we want to load the Gtk+3 library in a subprocess, and since we already
@@ -161,7 +161,7 @@ void glxtest()
     fatal_error("The MOZ_AVOID_OPENGL_ALTOGETHER environment variable is defined");
 
   ///// Open libGL and load needed symbols /////
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
   #define LIBGL_FILENAME "libGL.so"
 #else
   #define LIBGL_FILENAME "libGL.so.1"
