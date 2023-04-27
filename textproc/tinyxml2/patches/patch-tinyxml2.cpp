$NetBSD: patch-tinyxml2.cpp,v 1.1 2023/04/27 08:19:09 wiz Exp $

Add NetBSD support.

--- tinyxml2.cpp.orig	2021-06-07 00:10:24.000000000 +0000
+++ tinyxml2.cpp
@@ -103,7 +103,7 @@ distribution.
 #if defined(_WIN64)
 	#define TIXML_FSEEK _fseeki64
 	#define TIXML_FTELL _ftelli64
-#elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__ANDROID__)
+#elif defined(__APPLE__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__ANDROID__)
 	#define TIXML_FSEEK fseeko
 	#define TIXML_FTELL ftello
 #elif defined(__unix__) && defined(__x86_64__)
