$NetBSD: patch-src_3rdparty_chromium_third__party_swiftshader_src_OpenGL_libEGL_libEGL.cpp,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/swiftshader/src/OpenGL/libEGL/libEGL.cpp.orig	2020-07-15 19:01:39.000000000 +0000
+++ src/3rdparty/chromium/third_party/swiftshader/src/OpenGL/libEGL/libEGL.cpp
@@ -153,7 +153,7 @@ EGLDisplay EGLAPIENTRY GetDisplay(EGLNat
 		// FIXME: Check if display_id is the default display
 	}
 
-	#if defined(__linux__) && !defined(__ANDROID__)
+	#if (defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)) && !defined(__ANDROID__)
 		#if defined(USE_X11)
 		if(!libX11)
 		#endif  // Non X11 linux is headless only
@@ -216,7 +216,7 @@ const char *EGLAPIENTRY QueryString(EGLD
 	{
 		return success(
 			"EGL_KHR_client_get_all_proc_addresses "
-#if defined(__linux__) && !defined(__ANDROID__)
+#if (defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)) && !defined(__ANDROID__)
 			"EGL_KHR_platform_gbm "
 #endif
 #if defined(USE_X11)
@@ -1298,7 +1298,7 @@ EGLDisplay EGLAPIENTRY GetPlatformDispla
 {
 	TRACE("(EGLenum platform = 0x%X, void *native_display = %p, const EGLAttrib *attrib_list = %p)", platform, native_display, attrib_list);
 
-	#if defined(__linux__) && !defined(__ANDROID__)
+	#if (defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)) && !defined(__ANDROID__)
 		switch(platform)
 		{
 		#if defined(USE_X11)
