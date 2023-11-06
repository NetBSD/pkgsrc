$NetBSD: patch-src_config.c,v 1.1 2023/11/06 11:08:52 nia Exp $

Include the correct headers for realpath(3), PATH_MAX.

Should help SunOS.

--- src/config.c.orig	2023-01-02 08:39:00.000000000 +0000
+++ src/config.c
@@ -12,6 +12,8 @@
 
 #include <libgen.h>
 #include <unistd.h>
+#include <stdlib.h>
+#include <limits.h>
 
 #include <xkbcommon/xkbcommon.h>
 
