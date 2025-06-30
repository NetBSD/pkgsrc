$NetBSD: patch-cmake_QtSyncQtHelpers.cmake,v 1.3 2025/06/30 15:18:49 adam Exp $

Make sure syncqt is built before being used when building with make.

--- cmake/QtSyncQtHelpers.cmake.orig	2025-05-28 10:22:57.000000000 +0000
+++ cmake/QtSyncQtHelpers.cmake
@@ -254,6 +254,7 @@ function(qt_internal_target_sync_headers
             ${module_headers_for_docs}
             ${syncqt_all_args_rsp}
             ${QT_CMAKE_EXPORT_NAMESPACE}::syncqt
+            $<$<STREQUAL:${PROJECT_NAME},QtBase>:syncqt_build>
         VERBATIM
     )
 
