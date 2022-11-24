$NetBSD: patch-cmake_QtBaseGlobalTargets.cmake,v 1.1 2022/11/24 11:11:38 nros Exp $

* Only install non-generated files, this is needed since use in source build
* Don't install files bat.in files as thay are set to executable but not used
  by pkgsrc systems
* Don't install the directories under cmake/ since they create empty dirs on
  some platforms, files in them are installed anyway through other directives

--- cmake/QtBaseGlobalTargets.cmake.orig	2022-11-03 12:40:18.000000000 +0000
+++ cmake/QtBaseGlobalTargets.cmake
@@ -294,14 +294,14 @@ qt_copy_or_install(DIRECTORY
     "config.tests/static_link_order"
     "config.tests/binary_for_strip"
     DESTINATION "${__GlobalConfig_install_dir}/config.tests"
+    FILES_MATCHING PATTERN "*.cpp"
+    PATTERN "CMakeLists.txt"
 )
 
 # Install qt-internal-strip and qt-internal-ninja files.
 set(__qt_internal_strip_wrappers
     libexec/qt-internal-strip.in
-    libexec/qt-internal-strip.bat.in
     libexec/qt-internal-ninja.in
-    libexec/qt-internal-ninja.bat.in
 )
 qt_copy_or_install(PROGRAMS
     ${__qt_internal_strip_wrappers}
@@ -365,6 +365,10 @@ qt_copy_or_install(DIRECTORY cmake/
     FILES_MATCHING PATTERN "Find*.cmake"
     PATTERN "tests" EXCLUDE
     PATTERN "3rdparty" EXCLUDE
+    PATTERN "ios" EXCLUDE
+    PATTERN "macos" EXCLUDE
+    PATTERN "platforms" EXCLUDE
+    PATTERN "QtBuildInternals" EXCLUDE
 )
 
 # In prefix builds we also need to copy the files into the build config directory, so that the
@@ -375,6 +379,10 @@ if(QT_WILL_INSTALL)
         FILES_MATCHING PATTERN "Find*.cmake"
         PATTERN "tests" EXCLUDE
         PATTERN "3rdparty" EXCLUDE
+        PATTERN "ios" EXCLUDE
+        PATTERN "macos" EXCLUDE
+        PATTERN "platforms" EXCLUDE
+        PATTERN "QtBuildInternals" EXCLUDE
     )
 endif()
 
