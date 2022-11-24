$NetBSD: patch-src_network_configure.cmake,v 1.1 2022/11/24 11:11:38 nros Exp $

* add libraries needed for networking on solaris

--- src/network/configure.cmake.orig	2022-03-27 12:50:42.000000000 +0000
+++ src/network/configure.cmake
@@ -56,6 +56,7 @@ SSL_free(SSL_new(0));
 qt_find_package(GSSAPI PROVIDED_TARGETS GSSAPI::GSSAPI MODULE_NAME network QMAKE_LIB gssapi)
 qt_find_package(GLIB2 OPTIONAL_COMPONENTS GOBJECT PROVIDED_TARGETS GLIB2::GOBJECT MODULE_NAME core QMAKE_LIB gobject)
 qt_find_package(GLIB2 OPTIONAL_COMPONENTS GIO PROVIDED_TARGETS GLIB2::GIO MODULE_NAME core QMAKE_LIB gio)
+qt_test_lib_target(TARGET QtTEST::needed_network_libs LIBS socket nsl)
 
 
 #### Tests
@@ -63,6 +64,7 @@ qt_find_package(GLIB2 OPTIONAL_COMPONENT
 # getifaddrs
 qt_config_compile_test(getifaddrs
     LABEL "getifaddrs()"
+    LIBRARIES QtTEST::needed_network_libs
     CODE
 "#include <sys/types.h>
 #include <sys/socket.h>
@@ -100,6 +102,7 @@ req.ifr_index = 0;
 # ipv6ifname
 qt_config_compile_test(ipv6ifname
     LABEL "IPv6 ifname"
+    LIBRARIES QtTEST::needed_network_libs
     CODE
 "#include <sys/types.h>
 #include <sys/socket.h>
