$NetBSD: patch-kdecore_network_ConfigureChecks.cmake,v 1.1 2012/07/07 11:52:29 markd Exp $

Need netinet/in.h to successfully test for sockaddr_in6 on NetBSD

--- kdecore/network/ConfigureChecks.cmake.orig	2012-06-06 20:49:52.325046002 +0000
+++ kdecore/network/ConfigureChecks.cmake
@@ -57,6 +57,6 @@ check_prototype_exists(gai_strerror netd
 # check for existing datatypes
 set(CMAKE_EXTRA_INCLUDE_FILES "sys/socket.h;netdb.h")
 check_type_size("struct addrinfo" HAVE_STRUCT_ADDRINFO)
-set(CMAKE_EXTRA_INCLUDE_FILES "sys/socket.h;netdb.h")
+set(CMAKE_EXTRA_INCLUDE_FILES "netinet/in.h;sys/socket.h;netdb.h")
 check_type_size("struct sockaddr_in6" HAVE_STRUCT_SOCKADDR_IN6)
 set(CMAKE_EXTRA_INCLUDE_FILES)  #reset CMAKE_EXTRA_INCLUDE_FILES
