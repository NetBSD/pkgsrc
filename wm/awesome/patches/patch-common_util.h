$NetBSD: patch-common_util.h,v 1.1 2012/08/31 09:26:29 marino Exp $

DragonFly needs alloca.h too.

--- common/util.h.orig	2012-07-15 10:12:21.000000000 +0000
+++ common/util.h
@@ -32,7 +32,10 @@
 #include <assert.h>
 #include <stdio.h>
 
-#if !(defined (__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__))
+#if !(defined (__FreeBSD__) \
+   || defined(__DragonFly__) \
+   || defined(__OpenBSD__) \
+   || defined(__NetBSD__))
 #include <alloca.h>
 #endif
 
