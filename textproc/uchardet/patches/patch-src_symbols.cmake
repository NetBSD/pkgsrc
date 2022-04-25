$NetBSD: patch-src_symbols.cmake,v 1.1 2022/04/25 23:16:50 tnn Exp $

Need to patch this to avoid cwrappers splitting -Wl,,
Otherwise BUILDLINK_TRANSFORM cannot catch it.

--- src/symbols.cmake.orig	2020-04-23 09:48:58.000000000 +0000
+++ src/symbols.cmake
@@ -24,7 +24,7 @@ elseif (CMAKE_CXX_COMPILER_ID STREQUAL G
 	set(_version_script "${CMAKE_CURRENT_BINARY_DIR}/version.script")
 	file(WRITE ${_version_script} "${_symbols}\n")
 
-	set(LINK_FLAGS "${LINK_FLAGS} -Wl,--version-script,\"${_version_script}\"")
+	set(LINK_FLAGS "${LINK_FLAGS} -Wl,--version-script=\"${_version_script}\"")
 endif (APPLE)
 
 set_target_properties(
