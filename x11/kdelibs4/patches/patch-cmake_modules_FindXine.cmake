$NetBSD: patch-cmake_modules_FindXine.cmake,v 1.1 2012/03/22 22:08:30 markd Exp $

Starting with the recently released version 1.2.0, xine has its version
number macros in xine/version.h instead of xine.h itself.

Account for this case by checking if xine/version.h exists and falling
back to xine.h if it doesn't when reading the version numbers.

--- cmake/modules/FindXine.cmake.orig	2012-01-18 18:06:22.000000000 +0000
+++ cmake/modules/FindXine.cmake
@@ -47,7 +47,13 @@ FIND_PROGRAM(XINECONFIG_EXECUTABLE NAMES
 
 # Get the version number from xine.h and store it in the cache:
 IF(XINE_INCLUDE_DIR  AND NOT  XINE_VERSION)
-  FILE(READ ${XINE_INCLUDE_DIR}/xine.h XINE_VERSION_CONTENT)
+  IF(EXISTS ${XINE_INCLUDE_DIR}/xine/version.h) # xine 1.2.0+
+    SET(XINE_VERSION_FILE ${XINE_INCLUDE_DIR}/xine/version.h)
+  ELSE(EXISTS ${XINE_INCLUDE_DIR}/xine/version.h)
+    SET(XINE_VERSION_FILE ${XINE_INCLUDE_DIR}/xine.h)
+  ENDIF(EXISTS ${XINE_INCLUDE_DIR}/xine/version.h)
+
+  FILE(READ ${XINE_VERSION_FILE} XINE_VERSION_CONTENT)
   STRING(REGEX MATCH "#define *XINE_MAJOR_VERSION *([0-9]+)"  _dummy "${XINE_VERSION_CONTENT}")
   SET(XINE_VERSION_MAJOR "${CMAKE_MATCH_1}")
 
