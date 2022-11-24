$NetBSD: patch-cmake_QtFeature.cmake,v 1.1 2022/11/24 11:11:38 nros Exp $

* add function so that libraries such as socket and nsl 
  can be added to tests

--- cmake/QtFeature.cmake.orig	2022-03-27 12:50:42.000000000 +0000
+++ cmake/QtFeature.cmake
@@ -1254,3 +1254,22 @@ function(qt_make_features_available targ
         endforeach()
     endforeach()
 endfunction()
+
+# function to add libs to an INTERFACE library target if the lib exists,
+# needed because qt_config_compile test only accepts imported targets in its
+# LIBRARIES argument if PROJECT_PATH is not set.
+function(qt_test_lib_target)
+qt_parse_all_arguments(arg "qt_test_lib_target" "" "TARGET" "LIBS" ${ARGN})
+ 
+if(TARGET ${arg_TARGET})
+return()
+endif()
+add_library(${arg_TARGET} INTERFACE IMPORTED)
+foreach(_lib ${arg_LIBS})
+find_library(fl_${_lib} NAMES ${_lib})
+if(fl_${_lib})
+target_link_libraries(${arg_TARGET} INTERFACE ${fl_${_lib}})
+endif()
+endforeach()
+
+endfunction()
