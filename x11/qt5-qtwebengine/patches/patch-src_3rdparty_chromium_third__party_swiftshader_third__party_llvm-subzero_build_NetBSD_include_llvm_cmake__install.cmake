$NetBSD: patch-src_3rdparty_chromium_third__party_swiftshader_third__party_llvm-subzero_build_NetBSD_include_llvm_cmake__install.cmake,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/swiftshader/third_party/llvm-subzero/build/NetBSD/include/llvm/cmake_install.cmake.orig	2020-07-23 08:46:21.684214528 +0000
+++ src/3rdparty/chromium/third_party/swiftshader/third_party/llvm-subzero/build/NetBSD/include/llvm/cmake_install.cmake
@@ -0,0 +1,41 @@
+# Install script for directory: /home/ryoon/tmp4/llvm-7.0.1.src/include/llvm
+
+# Set the install prefix
+if(NOT DEFINED CMAKE_INSTALL_PREFIX)
+  set(CMAKE_INSTALL_PREFIX "/usr/local")
+endif()
+string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")
+
+# Set the install configuration name.
+if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
+  if(BUILD_TYPE)
+    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
+           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
+  else()
+    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
+  endif()
+  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
+endif()
+
+# Set the component getting installed.
+if(NOT CMAKE_INSTALL_COMPONENT)
+  if(COMPONENT)
+    message(STATUS "Install component: \"${COMPONENT}\"")
+    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
+  else()
+    set(CMAKE_INSTALL_COMPONENT)
+  endif()
+endif()
+
+# Is this installation the result of a crosscompile?
+if(NOT DEFINED CMAKE_CROSSCOMPILING)
+  set(CMAKE_CROSSCOMPILING "FALSE")
+endif()
+
+if(NOT CMAKE_INSTALL_LOCAL_ONLY)
+  # Include the install script for each subdirectory.
+  include("/home/ryoon/tmp4/build/include/llvm/IR/cmake_install.cmake")
+  include("/home/ryoon/tmp4/build/include/llvm/Support/cmake_install.cmake")
+
+endif()
+
