$NetBSD: patch-cmake_modules_FindTaglib.cmake,v 1.1 2011/06/04 16:31:52 abs Exp $

--- cmake/modules/FindTaglib.cmake.orig	2008-07-22 00:05:18.000000000 +0000
+++ cmake/modules/FindTaglib.cmake
@@ -11,7 +11,7 @@
 # For details see the accompanying COPYING-CMAKE-SCRIPTS file.
 
 if(NOT TAGLIB_MIN_VERSION)
-  set(TAGLIB_MIN_VERSION "1.4")
+  set(TAGLIB_MIN_VERSION "1.10")
 endif(NOT TAGLIB_MIN_VERSION)
 
 if(NOT WIN32)
