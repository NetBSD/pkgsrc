$NetBSD: patch-lib_Xm-2.1_Xpmcreate.c,v 1.1 2025/12/18 09:16:43 nia Exp $

Include <strings.h> for bzero.

--- lib/Xm-2.1/Xpmcreate.c.orig	2025-12-18 08:49:09.427964925 +0000
+++ lib/Xm-2.1/Xpmcreate.c
@@ -54,6 +54,7 @@
    DebugUtil.h! */
 #include <stdio.h>
 #include <string.h>
+#include <strings.h>
 
 #include <ctype.h>
 #ifdef HAVE_SYS_TYPES_H
