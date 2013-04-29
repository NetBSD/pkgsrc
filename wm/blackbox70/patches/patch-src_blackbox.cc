$NetBSD: patch-src_blackbox.cc,v 1.1 2013/04/29 21:27:15 joerg Exp $

--- src/blackbox.cc.orig	2013-04-28 13:04:23.000000000 +0000
+++ src/blackbox.cc
@@ -35,6 +35,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <assert.h>
+#include <stdlib.h>
 #include <signal.h>
 #include <unistd.h>
 
