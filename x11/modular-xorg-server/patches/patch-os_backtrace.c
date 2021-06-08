$NetBSD: patch-os_backtrace.c,v 1.1 2021/06/08 22:51:11 khorben Exp $

Fix build on Solaris 10/amd64 (from pkg/56169)

--- os/backtrace.c.orig	2021-04-13 14:11:40.000000000 +0000
+++ os/backtrace.c
@@ -29,6 +29,7 @@
 #include "misc.h"
 #include <errno.h>
 #include <string.h>
+#include <unistd.h>
 
 #ifdef HAVE_LIBUNWIND
 
