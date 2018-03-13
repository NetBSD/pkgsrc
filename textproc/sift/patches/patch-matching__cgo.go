$NetBSD: patch-matching__cgo.go,v 1.1 2018/03/13 17:28:59 bsiegert Exp $

The -funroll-loops flag is not on the compiler flag whitelist.

--- matching_cgo.go.orig	2015-12-23 00:37:41.000000000 +0000
+++ matching_cgo.go
@@ -16,7 +16,7 @@
 package main
 
 /*
-#cgo CFLAGS: -std=gnu99 -O2 -funroll-loops
+#cgo CFLAGS: -std=gnu99 -O2
 
 #include <stddef.h>
 
