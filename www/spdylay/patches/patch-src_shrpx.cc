$NetBSD: patch-src_shrpx.cc,v 1.1 2015/06/03 11:00:15 fhajny Exp $

Fixes SSIZE_MAX not declared.

--- src/shrpx.cc.orig	2015-03-12 15:39:31.000000000 +0000
+++ src/shrpx.cc
@@ -36,7 +36,7 @@
 #include <getopt.h>
 #include <syslog.h>
 
-#include <limits>
+#include <limits.h>
 #include <cstdlib>
 #include <iostream>
 #include <fstream>
