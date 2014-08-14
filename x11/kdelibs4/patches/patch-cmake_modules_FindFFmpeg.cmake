$NetBSD: patch-cmake_modules_FindFFmpeg.cmake,v 1.1 2014/08/14 13:03:23 wiz Exp $

Fix detection using pkg-config.
https://bugs.kde.org/show_bug.cgi?id=338266

--- cmake/modules/FindFFmpeg.cmake.orig	2014-08-14 11:43:40.000000000 +0000
+++ cmake/modules/FindFFmpeg.cmake
@@ -62,7 +62,7 @@ macro(find_component _component _pkgconf
      # in the FIND_PATH() and FIND_LIBRARY() calls
      find_package(PkgConfig)
      if (PKG_CONFIG_FOUND)
-       pkg_check_modules(PC_${_component} ${_pkgconfig})
+       pkg_check_modules(PC_LIB${_component} ${_pkgconfig})
      endif ()
   endif (NOT WIN32)
 
