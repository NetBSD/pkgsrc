$NetBSD: patch-build_cmake_config.cmake,v 1.3 2023/10/19 14:40:00 wiz Exp $

Respect ${CMAKE_INSTALL_BINDIR} instead of assuming bin

--- build/cmake/config.cmake.orig	2023-10-07 14:28:50.000000000 +0000
+++ build/cmake/config.cmake
@@ -107,11 +107,13 @@ endfunction()
 
 function(wx_write_config)
 
+    include(GNUInstallDirs)
+
     set(prefix ${CMAKE_INSTALL_PREFIX})
     set(exec_prefix "\${prefix}")
     set(includedir "\${prefix}/include")
     set(libdir "\${exec_prefix}/lib")
-    set(bindir "\${exec_prefix}/bin")
+    set(bindir "\${exec_prefix}/${CMAKE_INSTALL_BINDIR}")
 
     if(wxBUILD_MONOLITHIC)
         set(MONOLITHIC 1)
