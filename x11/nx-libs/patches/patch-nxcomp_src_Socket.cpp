$NetBSD: patch-nxcomp_src_Socket.cpp,v 1.1 2021/02/24 18:38:43 hauke Exp $

Add NetBSD conditional where we find FreeBSD's.

--- nxcomp/src/Socket.cpp.orig	2019-08-27 13:46:39.000000000 +0000
+++ nxcomp/src/Socket.cpp
@@ -30,7 +30,7 @@
 #include <sys/types.h>
 #include <sys/utsname.h>
 
-#if defined(__CYGWIN32__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__sun)
+#if defined(__CYGWIN32__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__sun)
 #include <netinet/in_systm.h>
 #endif
 
@@ -51,7 +51,7 @@
 // System specific defines.
 //
 
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__sun)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__sun)
 #define SOL_IP  IPPROTO_IP
 #endif
 
