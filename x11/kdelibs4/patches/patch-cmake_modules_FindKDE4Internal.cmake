$NetBSD: patch-cmake_modules_FindKDE4Internal.cmake,v 1.4 2016/02/18 23:24:46 jperkin Exp $

Don't force -std=iso9899:1990.
Disable Darwin bundles.

--- cmake/modules/FindKDE4Internal.cmake.orig	2015-12-08 15:49:30.000000000 +0000
+++ cmake/modules/FindKDE4Internal.cmake
@@ -889,10 +889,10 @@ set(INSTALL_TARGETS_DEFAULT_ARGS  RUNTIM
 
 
 # on the Mac support an extra install directory for application bundles starting with cmake 2.6
-if(APPLE)
+if(notAPPLE)
    set(INSTALL_TARGETS_DEFAULT_ARGS  ${INSTALL_TARGETS_DEFAULT_ARGS}
                                BUNDLE DESTINATION "${BUNDLE_INSTALL_DIR}" )
-endif(APPLE)
+endif(notAPPLE)
 
 
 ##############  add some more default search paths  ###############
@@ -1004,9 +1004,9 @@ if (UNIX)
    # here the defaults are set
    # which are partly overwritten in kde4_handle_rpath_for_library()
    # and kde4_handle_rpath_for_executable(), both located in KDE4Macros.cmake, Alex
-   if (APPLE)
+   if (notAPPLE)
       set(CMAKE_INSTALL_NAME_DIR ${LIB_INSTALL_DIR})
-   else (APPLE)
+   else (notAPPLE)
       # add our LIB_INSTALL_DIR to the RPATH (but only when it is not one of the standard system link
       # directories listed in CMAKE_{PLATFORM,C,CXX}_IMPLICIT_LINK_DIRECTORIES) and use the RPATH figured out by cmake when compiling
 
@@ -1020,7 +1020,7 @@ if (UNIX)
       set(CMAKE_SKIP_BUILD_RPATH FALSE)
       set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
       set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
-   endif (APPLE)
+   endif (notAPPLE)
 endif (UNIX)
 
 
@@ -1176,7 +1176,7 @@ if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_C_FLAGS_DEBUGFULL        "-g3 -fno-inline")
    set(CMAKE_C_FLAGS_PROFILE          "-g3 -fno-inline -ftest-coverage -fprofile-arcs")
 
-   set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -Wno-long-long -std=iso9899:1990 -Wundef -Wcast-align -Werror-implicit-function-declaration -Wchar-subscripts -Wall -W -Wpointer-arith -Wwrite-strings -Wformat-security -Wmissing-format-attribute -fno-common")
+   set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -Wno-long-long -Wundef -Wcast-align -Werror-implicit-function-declaration -Wchar-subscripts -Wall -W -Wpointer-arith -Wwrite-strings -Wformat-security -Wmissing-format-attribute -fno-common")
    # As of Qt 4.6.x we need to override the new exception macros if we want compile with -fno-exceptions
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wnon-virtual-dtor -Wno-long-long -Wundef -Wcast-align -Wchar-subscripts -Wall -W -Wpointer-arith -Wformat-security -fno-exceptions -DQT_NO_EXCEPTIONS -fno-check-new -fno-common")
 
@@ -1319,7 +1319,7 @@ if (CMAKE_CXX_COMPILER_ID STREQUAL "Clan
    set(CMAKE_C_FLAGS_DEBUGFULL        "-g3 -fno-inline")
    set(CMAKE_C_FLAGS_PROFILE          "-g3 -fno-inline -ftest-coverage -fprofile-arcs")
 
-   set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -Wno-long-long -std=iso9899:1990 -Wundef -Wcast-align -Werror-implicit-function-declaration -Wchar-subscripts -Wall -W -Wpointer-arith -Wwrite-strings -Wformat-security -Wmissing-format-attribute -fno-common")
+   set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -Wno-long-long -Wundef -Wcast-align -Werror-implicit-function-declaration -Wchar-subscripts -Wall -W -Wpointer-arith -Wwrite-strings -Wformat-security -Wmissing-format-attribute -fno-common")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wnon-virtual-dtor -Wno-long-long -Wundef -Wcast-align -Wchar-subscripts -Wall -W -Wpointer-arith -Wformat-security -Woverloaded-virtual -fno-common -fvisibility=hidden -Werror=return-type -fvisibility-inlines-hidden")
    set(KDE4_C_FLAGS    "-fvisibility=hidden")
 
