$NetBSD: patch-src_3rdparty_chromium_third__party_swiftshader_src_OpenGL_libEGL_Display.cpp,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/swiftshader/src/OpenGL/libEGL/Display.cpp.orig	2020-07-15 19:01:39.000000000 +0000
+++ src/3rdparty/chromium/third_party/swiftshader/src/OpenGL/libEGL/Display.cpp
@@ -691,7 +691,7 @@ bool Display::isValidWindow(EGLNativeWin
 			return status != 0;
 		}
 		return false;
-	#elif defined(__linux__)
+	#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 		return false;  // Non X11 linux is headless only
 	#elif defined(__APPLE__)
 		return sw::OSX::IsValidWindow(window);
@@ -869,7 +869,7 @@ sw::Format Display::getDisplayFormat() c
 		{
 			return sw::FORMAT_X8R8G8B8;
 		}
-	#elif defined(__linux__)  // Non X11 linux is headless only
+	#elif defined(__linux__)  || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) // Non X11 linux is headless only
 		return sw::FORMAT_A8B8G8R8;
 	#elif defined(__APPLE__)
 		return sw::FORMAT_A8B8G8R8;
