$NetBSD: patch-cmake_QtConfigureHelpers.cmake,v 1.1 2025/12/21 09:38:12 markd Exp $

use sh not bash

--- cmake/QtConfigureHelpers.cmake.orig	2025-05-29 01:27:28.000000000 +0000
+++ cmake/QtConfigureHelpers.cmake
@@ -191,7 +191,7 @@ endfunction()
 
 function(qt_webengine_configure_check_for_ulimit)
     message(STATUS "Checking 'ulimit -n'")
-    execute_process(COMMAND bash -c "ulimit -n"
+    execute_process(COMMAND sh -c "ulimit -n"
         OUTPUT_VARIABLE ulimit_output
     )
     string(REGEX MATCHALL "[0-9]+" limit "${ulimit_output}")
@@ -200,7 +200,7 @@ function(qt_webengine_configure_check_fo
         if(NOT ${CMAKE_VERSION} VERSION_LESS "3.21.0")
             message(STATUS "Creating linker launcher")
             file(GENERATE OUTPUT ${PROJECT_BINARY_DIR}/linker_ulimit.sh
-                CONTENT "#!/bin/bash\nulimit -n 4096\nexec \"$@\""
+                CONTENT "#!/bin/sh\nulimit -n 4096\nexec \"$@\""
                 FILE_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
             )
             set(COIN_BUG_699 ON PARENT_SCOPE)
