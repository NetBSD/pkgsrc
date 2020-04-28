$NetBSD: patch-General.h,v 1.1 2020/04/28 15:28:57 nikita Exp $

--- General.h.orig	2014-11-16 19:34:19.000000000 +0000
+++ General.h
@@ -12,7 +12,7 @@
 #undef _POSIX_SOURCE
 #endif
 
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 #define _POSIX_SOURCE 1
 #endif
 
