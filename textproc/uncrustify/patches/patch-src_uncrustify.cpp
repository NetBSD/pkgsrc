$NetBSD: patch-src_uncrustify.cpp,v 1.1 2013/04/29 21:31:13 joerg Exp $

--- src/uncrustify.cpp.orig	2013-04-29 19:04:36.000000000 +0000
+++ src/uncrustify.cpp
@@ -25,6 +25,7 @@
 #include <cstring>
 #include <cerrno>
 #include <fcntl.h>
+#include <unistd.h>
 #include "unc_ctype.h"
 #ifdef HAVE_SYS_STAT_H
 #include <sys/stat.h>
