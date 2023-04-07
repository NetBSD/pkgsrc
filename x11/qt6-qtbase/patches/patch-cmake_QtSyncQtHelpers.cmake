$NetBSD: patch-cmake_QtSyncQtHelpers.cmake,v 1.1 2023/04/07 18:28:05 nros Exp $

* make sure syncqt is built before being used when building with make

--- cmake/QtSyncQtHelpers.cmake.orig	2023-04-06 21:34:52.245729498 +0000
+++ cmake/QtSyncQtHelpers.cmake
@@ -163,6 +163,7 @@ function(qt_internal_target_sync_headers
             ${syncqt_args_rsp}
             ${module_headers}
             ${QT_CMAKE_EXPORT_NAMESPACE}::syncqt
+            $<$<STREQUAL:${PROJECT_NAME},QtBase>:syncqt_build>
         COMMENT
             "Running syncqt.cpp for module: ${module}"
         VERBATIM
@@ -190,6 +191,7 @@ function(qt_internal_target_sync_headers
             ${syncqt_all_args_rsp}
             ${QT_CMAKE_EXPORT_NAMESPACE}::syncqt
             ${target}_sync_headers
+            $<$<STREQUAL:${PROJECT_NAME},QtBase>:syncqt_build>
         VERBATIM
     )
 
