$NetBSD: patch-cmake_QtProcessConfigureArgs.cmake,v 1.4 2024/12/26 22:20:15 adam Exp $

* add function so that libraries such as socket and nsl 
  can be added to tests

* add support for avoiding the cmake archiving api using configure since
  libarchive in pkgsrc that cmake uses is built without zstd support

--- cmake/QtProcessConfigureArgs.cmake.orig	2024-11-12 10:55:11.000000000 +0000
+++ cmake/QtProcessConfigureArgs.cmake
@@ -266,6 +266,7 @@ defstub(qt_internal_extend_sbom)
 defstub(qt_internal_sbom_add_license)
 defstub(qt_internal_extend_sbom_dependencies)
 defstub(qt_find_package_extend_sbom)
+defstub(qt_test_lib_target)
 
 ####################################################################################################
 # Define functions/macros that are called in qt_cmdline.cmake files
@@ -936,6 +937,7 @@ translate_boolean_input(sbom-verify QT_S
 translate_boolean_input(sbom-verify-required QT_SBOM_REQUIRE_VERIFY)
 translate_boolean_input(shared BUILD_SHARED_LIBS)
 translate_boolean_input(warnings_are_errors WARNINGS_ARE_ERRORS)
+translate_boolean_input(avoid_cmake_archiving_api QT_AVOID_CMAKE_ARCHIVING_API)
 translate_boolean_input(qtinlinenamespace QT_INLINE_NAMESPACE)
 translate_string_input(qt_namespace QT_NAMESPACE)
 translate_string_input(qt_libinfix QT_LIBINFIX)
