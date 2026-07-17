$NetBSD: patch-Source_cmake_WebKitMacros.cmake,v 1.1 2026/07/17 05:52:30 wiz Exp $

Fix cmake syntax.

--- Source/cmake/WebKitMacros.cmake.orig	2026-07-17 05:18:50.633734793 +0000
+++ Source/cmake/WebKitMacros.cmake
@@ -282,7 +282,7 @@ macro(_WEBKIT_EXECUTABLE_LINK_FRAMEWORK _target)
         get_property(_linked_into GLOBAL PROPERTY ${framework}_LINKED_INTO)
 
         # See if the executable is linking a framework that the specified framework is already linked into
-        if ((NOT _linked_into) OR (${framework} STREQUAL ${_linked_into}) OR (NOT ${_linked_into} IN_LIST ${_target}_FRAMEWORKS))
+        if ((NOT _linked_into) OR (${framework} STREQUAL "${_linked_into}") OR (NOT "${_linked_into}" IN_LIST ${_target}_FRAMEWORKS))
             list(APPEND ${_target}_PRIVATE_LIBRARIES WebKit::${framework})
 
             # The WebKit:: alias targets do not propagate OBJECT libraries so the
