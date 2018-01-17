$NetBSD: patch-Source_WebKit_PlatformQt.cmake,v 1.1 2018/01/17 19:37:33 markd Exp $

Fix build with CMake 3.10

--- Source/WebKit/PlatformQt.cmake.orig	2017-06-09 14:11:36.000000000 +0000
+++ Source/WebKit/PlatformQt.cmake
@@ -786,6 +786,7 @@ if (COMPILER_IS_GCC_OR_CLANG)
     set_source_files_properties(
         qt/Api/qwebdatabase.cpp
         qt/Api/qwebelement.cpp
+        qt/Api/qwebfullscreenrequest.cpp
         qt/Api/qwebhistory.cpp
         qt/Api/qwebhistoryinterface.cpp
         qt/Api/qwebpluginfactory.cpp
@@ -795,7 +796,6 @@ if (COMPILER_IS_GCC_OR_CLANG)
 
         qt/WidgetApi/qgraphicswebview.cpp
         qt/WidgetApi/qwebframe.cpp
-        qt/WidgetApi/qwebfullscreenrequest.cpp
         qt/WidgetApi/qwebinspector.cpp
         qt/WidgetApi/qwebpage.cpp
         qt/WidgetApi/qwebview.cpp
