$NetBSD: patch-cmake_QtBuildInternals_QtBuildInternalsConfig.cmake,v 1.1 2022/11/24 11:11:38 nros Exp $

* Only run qt_copy_or_install if there are any Find*.cmake files to install,
  the reason to do this is that some qt6 packages has a cmake dir but no Find*.cmake
  files in it and in these cases an empty qt6/lib/cmake/Qt6 directory is created and
  we don't want that.

--- cmake/QtBuildInternals/QtBuildInternalsConfig.cmake.orig	2022-05-25 08:58:52.000000000 +0000
+++ cmake/QtBuildInternals/QtBuildInternalsConfig.cmake
@@ -477,16 +477,22 @@ macro(qt_build_repo_end)
 
         if(NOT PROJECT_NAME STREQUAL "QtBase")
             if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
-                qt_copy_or_install(DIRECTORY cmake/
-                    DESTINATION "${__qt_repo_install_dir}"
-                    FILES_MATCHING PATTERN "Find*.cmake"
-                )
-                if(QT_SUPERBUILD AND QT_WILL_INSTALL)
-                    file(COPY cmake/
-                         DESTINATION "${__qt_repo_build_dir}"
-                         FILES_MATCHING PATTERN "Find*.cmake"
+                file(GLOB_RECURSE find_files cmake/Find*.cmake)
+                list(LENGTH find_files have_find_files)
+                if(have_find_files)
+                    qt_copy_or_install(DIRECTORY cmake/
+                        DESTINATION "${__qt_repo_install_dir}"
+                        FILES_MATCHING PATTERN "Find*.cmake"
                     )
+                    if(QT_SUPERBUILD AND QT_WILL_INSTALL)
+                        file(COPY cmake/
+                             DESTINATION "${__qt_repo_build_dir}"
+                             FILES_MATCHING PATTERN "Find*.cmake"
+                        )
+                    endif()
                 endif()
+                unset(have_find_files)
+                unset(find_files)
             endif()
         endif()
 
