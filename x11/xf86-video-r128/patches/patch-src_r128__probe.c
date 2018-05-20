$NetBSD: patch-src_r128__probe.c,v 1.3 2018/05/20 07:19:18 wiz Exp $

Provide uint32_t.

--- src/r128_probe.c.orig	2017-01-17 22:42:44.000000000 +0000
+++ src/r128_probe.c
@@ -32,6 +32,7 @@
 #endif
 
 #include <string.h>
+#include <sys/types.h>
 
 /*
  * Authors:
