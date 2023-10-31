$NetBSD: patch-src_network_configure.cmake,v 1.2 2023/10/31 19:56:48 adam Exp $

* add libraries needed for networking on solaris

--- src/network/configure.cmake.orig	2023-09-13 16:02:48.000000000 +0000
+++ src/network/configure.cmake
@@ -13,12 +13,14 @@ qt_find_package(GSSAPI PROVIDED_TARGETS
 qt_find_package(GLIB2 OPTIONAL_COMPONENTS GOBJECT PROVIDED_TARGETS GLIB2::GOBJECT MODULE_NAME core QMAKE_LIB gobject)
 qt_find_package(GLIB2 OPTIONAL_COMPONENTS GIO PROVIDED_TARGETS GLIB2::GIO MODULE_NAME core QMAKE_LIB gio)
 qt_find_package(WrapResolv PROVIDED_TARGETS WrapResolv::WrapResolv MODULE_NAME network QMAKE_LIB libresolv)
+qt_test_lib_target(TARGET QtTEST::needed_network_libs LIBS socket nsl)
 
 #### Tests
 
 # getifaddrs
 qt_config_compile_test(getifaddrs
     LABEL "getifaddrs()"
+    LIBRARIES QtTEST::needed_network_libs
     CODE
 "#include <sys/types.h>
 #include <sys/socket.h>
@@ -56,6 +58,7 @@ req.ifr_index = 0;
 # ipv6ifname
 qt_config_compile_test(ipv6ifname
     LABEL "IPv6 ifname"
+    LIBRARIES QtTEST::needed_network_libs
     CODE
 "#include <sys/types.h>
 #include <sys/socket.h>
