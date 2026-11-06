$NetBSD: patch-cmake_QtSyncQtHelpers.cmake,v 1.4 2026/11/06 09:08:53 adam Exp $

Make sure syncqt is built before being used when building with make.

--- cmake/QtSyncQtHelpers.cmake.orig	2026-10-05 15:03:40.000000000 +0000
+++ cmake/QtSyncQtHelpers.cmake
@@ -258,6 +258,7 @@ function(qt_internal_target_sync_headers
             ${module_headers_generated_for_docs}
             ${syncqt_all_args_rsp}
             ${QT_CMAKE_EXPORT_NAMESPACE}::syncqt
+            $<$<STREQUAL:${PROJECT_NAME},QtBase>:syncqt_build>
         VERBATIM
     )
 
