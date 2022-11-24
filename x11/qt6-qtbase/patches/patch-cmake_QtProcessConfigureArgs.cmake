$NetBSD: patch-cmake_QtProcessConfigureArgs.cmake,v 1.1 2022/11/24 11:11:38 nros Exp $

* add function so that libraries such as socket and nsl 
  can be added to tests

* add support for avoiding the cmake archiving api using configure since
  libarchive in pkgsrc that cmake uses is built without zstd support

--- cmake/QtProcessConfigureArgs.cmake.orig	2022-03-27 12:50:42.000000000 +0000
+++ cmake/QtProcessConfigureArgs.cmake
@@ -177,6 +177,7 @@ defstub(set_package_properties)
 defstub(qt_qml_find_python)
 defstub(qt_set01)
 defstub(qt_internal_check_if_linker_is_available)
+defstub(qt_test_lib_target)
 
 ####################################################################################################
 # Define functions/macros that are called in qt_cmdline.cmake files
@@ -798,6 +799,7 @@ translate_boolean_input(precompile_heade
 translate_boolean_input(ccache QT_USE_CCACHE)
 translate_boolean_input(shared BUILD_SHARED_LIBS)
 translate_boolean_input(warnings_are_errors WARNINGS_ARE_ERRORS)
+translate_boolean_input(avoid_cmake_archiving_api QT_AVOID_CMAKE_ARCHIVING_API)
 translate_string_input(qt_namespace QT_NAMESPACE)
 translate_string_input(qt_libinfix QT_LIBINFIX)
 translate_string_input(qreal QT_COORD_TYPE)
