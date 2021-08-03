$NetBSD: patch-src_3rdparty_chromium_third__party_swiftshader_src_OpenGL_libEGL_Surface.cpp,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/swiftshader/src/OpenGL/libEGL/Surface.cpp.orig	2020-07-15 19:01:39.000000000 +0000
+++ src/3rdparty/chromium/third_party/swiftshader/src/OpenGL/libEGL/Surface.cpp
@@ -362,7 +362,7 @@ bool WindowSurface::checkForResize()
 
 		int windowWidth = windowAttributes.width;
 		int windowHeight = windowAttributes.height;
-	#elif defined(__linux__)
+	#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 		// Non X11 linux is headless only
 		int windowWidth = 100;
 		int windowHeight = 100;
