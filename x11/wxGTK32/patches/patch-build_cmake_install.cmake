$NetBSD: patch-build_cmake_install.cmake,v 1.2 2022/08/10 05:19:57 dbj Exp $

Fix use of DESTDIR
https://github.com/wxWidgets/wxWidgets/issues/22610

Respect ${CMAKE_INSTALL_BINDIR} instead of assuming bin

--- build/cmake/install.cmake.orig	2022-07-06 14:19:50.000000000 +0000
+++ build/cmake/install.cmake
@@ -39,11 +39,13 @@ else()
                     WORLD_EXECUTE WORLD_READ
         )
 
-    install(DIRECTORY DESTINATION "bin")
+    include(GNUInstallDirs)
+
+    install(DIRECTORY DESTINATION "${CMAKE_INSTALL_BINDIR}")
     install(CODE "execute_process( \
         COMMAND ${CMAKE_COMMAND} -E create_symlink \
         ${CMAKE_INSTALL_PREFIX}/lib/wx/config/${wxBUILD_FILE_ID} \
-        ${CMAKE_INSTALL_PREFIX}/bin/wx-config \
+        \"\$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}/wx-config\" \
         )"
     )
 endif()
@@ -96,8 +98,8 @@ if(NOT TARGET ${UNINST_NAME})
         endif()
 
         set(WX_EXTRA_UNINSTALL_FILES
-            "${CMAKE_INSTALL_PREFIX}/bin/wx-config"
-            "${CMAKE_INSTALL_PREFIX}/bin/wxrc${EXE_SUFFIX}"
+            "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}/wx-config"
+            "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}/wxrc${EXE_SUFFIX}"
         )
     endif()
 
