$NetBSD: patch-src_config.c,v 1.2 2025/12/27 15:37:50 wiz Exp $

Include the correct headers for realpath(3), PATH_MAX.

Should help SunOS.

--- src/config.c.orig	2025-12-19 07:19:53.000000000 +0000
+++ src/config.c
@@ -12,6 +12,8 @@
 
 #include <libgen.h>
 #include <xkbcommon/xkbcommon.h>
+#include <stdlib.h>
+#include <limits.h>
 
 char *current_configpath = NULL;
 Config config;
