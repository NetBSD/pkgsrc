$NetBSD: patch-cmake_modules_FindTaglib.cmake,v 1.2 2012/03/19 11:28:49 markd Exp $

Change the string comparision operator on the TAGLIB_VERSION to a 
version comparision operator (since versions are being compared.)

--- cmake/modules/FindTaglib.cmake.orig	2011-07-27 18:34:31.000000000 +0000
+++ cmake/modules/FindTaglib.cmake
@@ -29,10 +29,10 @@ if(TAGLIBCONFIG_EXECUTABLE)
 
   exec_program(${TAGLIBCONFIG_EXECUTABLE} ARGS --version RETURN_VALUE _return_VALUE OUTPUT_VARIABLE TAGLIB_VERSION)
 
-  if(TAGLIB_VERSION STRLESS "${TAGLIB_MIN_VERSION}")
+  if(TAGLIB_VERSION VERSION_LESS "${TAGLIB_MIN_VERSION}")
      message(STATUS "TagLib version not found: version searched :${TAGLIB_MIN_VERSION}, found ${TAGLIB_VERSION}")
      set(TAGLIB_FOUND FALSE)
-  else(TAGLIB_VERSION STRLESS "${TAGLIB_MIN_VERSION}")
+  else(TAGLIB_VERSION VERSION_LESS "${TAGLIB_MIN_VERSION}")
 
      exec_program(${TAGLIBCONFIG_EXECUTABLE} ARGS --libs RETURN_VALUE _return_VALUE OUTPUT_VARIABLE TAGLIB_LIBRARIES)
 
@@ -43,7 +43,7 @@ if(TAGLIBCONFIG_EXECUTABLE)
         message(STATUS "Found taglib: ${TAGLIB_LIBRARIES}")
      endif(TAGLIB_LIBRARIES AND TAGLIB_CFLAGS)
      string(REGEX REPLACE " *-I" ";" TAGLIB_INCLUDES "${TAGLIB_CFLAGS}")
-  endif(TAGLIB_VERSION STRLESS "${TAGLIB_MIN_VERSION}") 
+  endif(TAGLIB_VERSION VERSION_LESS "${TAGLIB_MIN_VERSION}") 
   mark_as_advanced(TAGLIB_CFLAGS TAGLIB_LIBRARIES TAGLIB_INCLUDES)
 
 else(TAGLIBCONFIG_EXECUTABLE)
