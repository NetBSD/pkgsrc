$NetBSD: patch-Source_cmake_OptionsQt.cmake,v 1.2 2019/07/20 18:29:33 nia Exp $

ECM_MODULE_DIR wants a single directory, not a path

--- Source/cmake/OptionsQt.cmake.orig	2019-06-26 16:25:02.000000000 +0000
+++ Source/cmake/OptionsQt.cmake
@@ -3,7 +3,7 @@ include(FeatureSummary)
 include(ECMEnableSanitizers)
 include(ECMPackageConfigHelpers)
 
-set(ECM_MODULE_DIR ${CMAKE_MODULE_PATH})
+set(ECM_MODULE_DIR "${CMAKE_SOURCE_DIR}/Source/cmake")
 
 set(PROJECT_VERSION_MAJOR 5)
 set(PROJECT_VERSION_MINOR 212)
