$NetBSD: patch-build_cmake_config.cmake,v 1.2 2022/08/10 05:19:57 dbj Exp $

Respect ${CMAKE_INSTALL_BINDIR} instead of assuming bin

--- build/cmake/config.cmake.orig	2022-07-06 14:19:50.000000000 +0000
+++ build/cmake/config.cmake
@@ -83,11 +83,13 @@ endfunction()
 
 function(wx_write_config)
 
+    include(GNUInstallDirs)
+
     set(prefix ${CMAKE_INSTALL_PREFIX})
     set(exec_prefix "\${prefix}")
     set(includedir "\${prefix}/include")
     set(libdir "\${exec_prefix}/lib")
-    set(bindir "\${exec_prefix}/bin")
+    set(bindir "\${exec_prefix}/${CMAKE_INSTALL_BINDIR}")
 
     find_program(EGREP egrep)
     mark_as_advanced(EGREP)
