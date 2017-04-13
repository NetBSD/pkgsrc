$NetBSD: patch-Source_cmake_OptionsGTK.cmake,v 1.12 2017/04/13 16:58:14 jperkin Exp $

o Do not require GCC 4.9.0 (should be build *without* IndexedDB support)
o Do not conflict with CMAKE_MODULE_PATH during the linking phase of
  libwebkit2gtk-4.0.so:

   Linking CXX shared library ../../lib/libwebkit2gtk-4.0.so
   ld:/usr/pkgsrc/wip/webkit-gtk/work/.buildlink/cmake-Modules:1: ignoring invalid character `3' in script
   [...]
   ld:/usr/pkgsrc/wip/webkit-gtk/work/.buildlink/cmake-Modules:1: syntax error in VERSION script
   Source/WebKit2/CMakeFiles/WebKit2.dir/build.make:16139: recipe for target 'lib/libwebkit2gtk-4.0.so.37.2.6' failed
   [...]

o Disable DatabaseProcess and IndexedDB support.
o Do not use --version-script on SunOS

--- Source/cmake/OptionsGTK.cmake.orig	2016-08-24 06:45:01.000000000 +0000
+++ Source/cmake/OptionsGTK.cmake
@@ -6,13 +6,6 @@ set(PROJECT_VERSION_MICRO 4)
 set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_MICRO})
 set(WEBKITGTK_API_VERSION 4.0)
 
-# IndexedDB support requires GCC 4.9, see https://bugs.webkit.org/show_bug.cgi?id=98932.
-if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
-    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.9.0")
-        message(FATAL_ERROR "GCC 4.9.0 is required to build WebKitGTK+, use a newer GCC version or clang")
-    endif ()
-endif ()
-
 # Libtool library version, not to be confused with API version.
 # See http://www.gnu.org/software/libtool/manual/html_node/Libtool-versioning.html
 CALCULATE_LIBRARY_VERSIONS_FROM_LIBTOOL_TRIPLE(WEBKIT2 50 10 13)
@@ -116,8 +109,8 @@ if (DEVELOPER_MODE)
 else ()
     WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_MINIBROWSER PUBLIC OFF)
     WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_API_TESTS PRIVATE OFF)
-    if (NOT CMAKE_SYSTEM_NAME MATCHES "Darwin")
-        set(WebKit2_VERSION_SCRIPT "-Wl,--version-script,${CMAKE_MODULE_PATH}/gtksymbols.filter")
+    if (NOT CMAKE_SYSTEM_NAME MATCHES "Darwin" AND NOT CMAKE_SYSTEM_NAME MATCHES "SunOS")
+        set(WebKit2_VERSION_SCRIPT "-Wl,--version-script,${CMAKE_SOURCE_DIR}/Source/cmake/gtksymbols.filter")
     endif ()
 endif ()
 
@@ -152,11 +145,11 @@ WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_
 WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS_IMAGE_SET PRIVATE ON)
 WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS_REGIONS PRIVATE ON)
 WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS_SELECTORS_LEVEL4 PRIVATE ON)
-WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_DATABASE_PROCESS PRIVATE ON)
+WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_DATABASE_PROCESS PRIVATE OFF)
 WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_FTL_JIT PRIVATE ${ENABLE_FTL_DEFAULT})
 WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_FTPDIR PRIVATE OFF)
 WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_FULLSCREEN_API PRIVATE ON)
-WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_INDEXED_DATABASE PRIVATE ON)
+WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_INDEXED_DATABASE PRIVATE OFF)
 WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_INDEXED_DATABASE_IN_WORKERS PRIVATE OFF)
 WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_INPUT_TYPE_COLOR PRIVATE ON)
 WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_LEGACY_WEB_AUDIO PRIVATE OFF)
