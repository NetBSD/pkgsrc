$NetBSD: patch-os_backtrace.c,v 1.3 2022/05/22 21:29:58 dholland Exp $

Use standard headers, needed on Solaris.

--- os/backtrace.c~	2021-12-15 19:01:24.000000000 +0000
+++ os/backtrace.c
@@ -29,6 +29,7 @@
 #include "misc.h"
 #include <errno.h>
 #include <string.h>
+#include <unistd.h>
 
 #ifdef HAVE_LIBUNWIND
 
