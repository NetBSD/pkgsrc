$NetBSD: patch-cmake_QtBaseGlobalTargets.cmake,v 1.4 2026/08/18 18:26:02 adam Exp $

* Only install non-generated files, this is needed since use in source build.
* Don't install files bat.in files as thay are set to executable but not used
  by pkgsrc systems.
* Don't install the directories under cmake/ since they create empty dirs on
  some platforms, files in them are installed anyway through other directives.

--- cmake/QtBaseGlobalTargets.cmake.orig	2026-05-11 20:54:55.000000000 +0000
+++ cmake/QtBaseGlobalTargets.cmake
@@ -326,6 +326,8 @@ set(__qt_internal_public_config_tests
 )
 qt_copy_or_install(DIRECTORY ${__qt_internal_public_config_tests}
     DESTINATION "${__GlobalConfig_install_dir}/config.tests"
+    FILES_MATCHING PATTERN "*.cpp"
+    PATTERN "CMakeLists.txt"
 )
 if(QT_WILL_INSTALL)
     file(COPY ${__qt_internal_public_config_tests}
@@ -343,7 +345,6 @@ set(__qt_internal_strip_wrapper_files
 )
 set(__qt_internal_strip_wrappers
     ${__qt_internal_strip_wrapper_programs}
-    ${__qt_internal_strip_wrapper_files}
 )
 qt_copy_or_install(PROGRAMS
     ${__qt_internal_strip_wrapper_programs}
