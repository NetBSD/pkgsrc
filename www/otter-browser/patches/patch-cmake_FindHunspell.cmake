$NetBSD: patch-cmake_FindHunspell.cmake,v 1.1 2019/05/16 23:22:15 gutteridge Exp $

Include newest hunspell library version.

--- cmake/FindHunspell.cmake.orig	2019-01-01 16:59:01.000000000 +0000
+++ cmake/FindHunspell.cmake
@@ -12,7 +12,7 @@ IF (HUNSPELL_INCLUDE_DIR AND HUNSPELL_LI
 ENDIF (HUNSPELL_INCLUDE_DIR AND HUNSPELL_LIBRARIES)
 
 FIND_PATH(HUNSPELL_INCLUDE_DIR hunspell/hunspell.hxx)
-FIND_LIBRARY(HUNSPELL_LIBRARIES NAMES hunspell-1.6 hunspell-1.5 hunspell)
+FIND_LIBRARY(HUNSPELL_LIBRARIES NAMES hunspell-1.7 hunspell-1.6 hunspell-1.5 hunspell)
 
 # handle the QUIETLY and REQUIRED arguments and set HUNSPELL_FOUND to TRUE if
 # all listed variables are TRUE
