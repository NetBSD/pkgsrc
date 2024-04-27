$NetBSD: patch-src_gui_configure.cmake,v 1.1 2024/04/27 11:49:40 adam Exp $

Support all UNIX platforms.

--- src/gui/configure.cmake.orig	2024-04-26 16:25:16.765900081 +0000
+++ src/gui/configure.cmake
@@ -60,7 +60,7 @@ qt_find_package(GLESv2 PROVIDED_TARGETS 
 qt_find_package(Tslib PROVIDED_TARGETS PkgConfig::Tslib MODULE_NAME gui QMAKE_LIB tslib)
 qt_find_package(WrapVulkanHeaders PROVIDED_TARGETS WrapVulkanHeaders::WrapVulkanHeaders
     MODULE_NAME gui QMAKE_LIB vulkan MARK_OPTIONAL)
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((UNIX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(Wayland PROVIDED_TARGETS Wayland::Server MODULE_NAME gui QMAKE_LIB wayland_server)
     qt_find_package(Wayland PROVIDED_TARGETS Wayland::Client MODULE_NAME gui QMAKE_LIB wayland_client)
 endif()
