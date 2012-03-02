$NetBSD: patch-config.hpp,v 1.1 2012/03/02 14:57:08 hans Exp $

--- config.hpp.orig	2005-06-20 13:28:29.000000000 +0200
+++ config.hpp	2012-03-02 15:50:39.263891839 +0100
@@ -35,6 +35,7 @@
 #define _GNU_SOURCE
 #endif
 #include <dirent.h>  // for PATH_MAX?
+#include <limits.h>
 #include <getopt.h>
 
 #include <X11/keysym.h>
