$NetBSD: patch-cmake_modules_FindHUNSPELL.cmake,v 1.1 2019/11/02 19:45:26 maya Exp $

Support hunspell 1.7

--- cmake/modules/FindHUNSPELL.cmake.orig	2019-11-02 19:43:18.547827922 +0000
+++ cmake/modules/FindHUNSPELL.cmake
@@ -14,7 +14,7 @@ ENDIF (HUNSPELL_INCLUDE_DIR AND HUNSPELL
 
 FIND_PATH(HUNSPELL_INCLUDE_DIR hunspell/hunspell.hxx )
 
-FIND_LIBRARY(HUNSPELL_LIBRARIES NAMES hunspell-2.0 hunspell-1.6 hunspell-1.5 hunspell-1.4 hunspell-1.3 hunspell-1.2)
+FIND_LIBRARY(HUNSPELL_LIBRARIES NAMES hunspell-2.0 hunspell-1.7 hunspell-1.6 hunspell-1.5 hunspell-1.4 hunspell-1.3 hunspell-1.2)
 
 # handle the QUIETLY and REQUIRED arguments and set HUNSPELL_FOUND to TRUE if 
 # all listed variables are TRUE
