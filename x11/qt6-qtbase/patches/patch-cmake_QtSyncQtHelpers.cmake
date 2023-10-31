$NetBSD: patch-cmake_QtSyncQtHelpers.cmake,v 1.2 2023/10/31 19:56:48 adam Exp $

* make sure syncqt is built before being used when building with make

--- cmake/QtSyncQtHelpers.cmake.orig	2023-09-13 16:02:48.000000000 +0000
+++ cmake/QtSyncQtHelpers.cmake
@@ -228,6 +228,7 @@ function(qt_internal_target_sync_headers
             ${syncqt_all_args_rsp}
             ${QT_CMAKE_EXPORT_NAMESPACE}::syncqt
             ${target}_sync_headers
+            $<$<STREQUAL:${PROJECT_NAME},QtBase>:syncqt_build>
         VERBATIM
     )
 
