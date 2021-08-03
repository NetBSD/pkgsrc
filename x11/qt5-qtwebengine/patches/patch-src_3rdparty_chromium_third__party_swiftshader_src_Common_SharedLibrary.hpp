$NetBSD: patch-src_3rdparty_chromium_third__party_swiftshader_src_Common_SharedLibrary.hpp,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/swiftshader/src/Common/SharedLibrary.hpp.orig	2020-07-15 19:01:39.000000000 +0000
+++ src/3rdparty/chromium/third_party/swiftshader/src/Common/SharedLibrary.hpp
@@ -97,7 +97,7 @@ void *loadLibrary(const std::string &lib
 
 	inline void *getLibraryHandle(const char *path)
 	{
-		#ifdef __ANDROID__
+		#if defined(__ANDROID__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 			// bionic doesn't support RTLD_NOLOAD before L
 			return dlopen(path, RTLD_NOW | RTLD_LOCAL);
 		#else
