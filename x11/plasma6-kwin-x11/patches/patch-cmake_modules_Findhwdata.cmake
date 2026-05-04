$NetBSD: patch-cmake_modules_Findhwdata.cmake,v 1.1 2026/05/04 11:08:21 markd Exp $

Look where pkgsrc installs hwdata

--- cmake/modules/Findhwdata.cmake.orig	2025-11-04 14:59:51.000000000 +0000
+++ cmake/modules/Findhwdata.cmake
@@ -10,8 +10,8 @@
 # SPDX-License-Identifier: BSD-3-Clause
 
 if (UNIX AND NOT APPLE)
-    find_path(hwdata_DIR NAMES hwdata/pnp.ids HINTS /usr/share ENV XDG_DATA_DIRS)
-    find_file(hwdata_PNPIDS_FILE NAMES hwdata/pnp.ids HINTS /usr/share)
+    find_path(hwdata_DIR NAMES hwdata/pnp.ids HINTS ${CMAKE_INSTALL_PREFIX}/share /usr/share ENV XDG_DATA_DIRS)
+    find_file(hwdata_PNPIDS_FILE NAMES hwdata/pnp.ids HINTS ${CMAKE_INSTALL_PREFIX}/share /usr/share)
     if (NOT hwdata_DIR OR NOT hwdata_PNPIDS_FILE)
         set(hwdata_FOUND FALSE)
     else()
