$NetBSD: patch-Source_cmake_OptionsGTK.cmake,v 1.1 2015/07/12 00:44:46 wiz Exp $

Do not conflict with CMAKE_MODULE_PATH during the linking phase of
libwebkit2gtk-4.0.so:

 Linking CXX shared library ../../lib/libwebkit2gtk-4.0.so
 ld:/usr/pkgsrc/wip/webkit-gtk/work/.buildlink/cmake-Modules:1: ignoring invalid character `3' in script
 [...]
 ld:/usr/pkgsrc/wip/webkit-gtk/work/.buildlink/cmake-Modules:1: syntax error in VERSION script
 Source/WebKit2/CMakeFiles/WebKit2.dir/build.make:16139: recipe for target 'lib/libwebkit2gtk-4.0.so.37.2.6' failed
 [...]

--- Source/cmake/OptionsGTK.cmake.orig	2015-03-23 09:45:19.000000000 +0000
+++ Source/cmake/OptionsGTK.cmake
@@ -143,7 +143,7 @@ if (DEVELOPER_MODE)
 else ()
     WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_MINIBROWSER OFF)
     WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_API_TESTS OFF)
-    set(WebKit2_VERSION_SCRIPT "-Wl,--version-script,${CMAKE_MODULE_PATH}/gtksymbols.filter")
+    set(WebKit2_VERSION_SCRIPT "-Wl,--version-script,${CMAKE_SOURCE_DIR}/Source/cmake/gtksymbols.filter")
 endif ()
 
 if (CMAKE_SYSTEM_NAME MATCHES "Linux")
