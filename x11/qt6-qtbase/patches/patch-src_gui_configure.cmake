$NetBSD: patch-src_gui_configure.cmake,v 1.2 2025/11/11 12:34:13 adam Exp $

Support all UNIX platforms.

--- src/gui/configure.cmake.orig	2025-10-01 09:37:05.000000000 +0000
+++ src/gui/configure.cmake
@@ -76,7 +76,7 @@ qt_find_package(GLESv2 MODULE
 qt_find_package(Tslib MODULE PROVIDED_TARGETS PkgConfig::Tslib MODULE_NAME gui QMAKE_LIB tslib)
 qt_find_package(WrapVulkanHeaders MODULE PROVIDED_TARGETS WrapVulkanHeaders::WrapVulkanHeaders
     MODULE_NAME gui QMAKE_LIB vulkan MARK_OPTIONAL)
-if(LINUX OR FREEBSD OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if(UNIX OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(Wayland MODULE PROVIDED_TARGETS Wayland::Server
                     MODULE_NAME gui QMAKE_LIB wayland_server)
     qt_find_package(Wayland MODULE PROVIDED_TARGETS Wayland::Client
