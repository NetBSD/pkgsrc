$NetBSD: patch-libtu_output.c,v 1.1.1.1 2012/01/08 15:22:14 wiz Exp $

Do not use snprintf from libtu, modern systems have it.

--- libtu/output.c.orig	2011-10-29 18:26:56.000000000 +0000
+++ libtu/output.c
@@ -7,9 +7,6 @@
  * the Clarified Artistic License or the GNU LGPL, version 2.1 or later.
  */
 
-#if HAS_SYSTEM_ASPRINTF
-#define _GNU_SOURCE
-#endif
 
 #include <stdio.h>
 #include <stdlib.h>
@@ -22,9 +19,6 @@
 #include "util.h"
 #include "private.h"
 
-#if !HAS_SYSTEM_ASPRINTF
-#include "snprintf_2.2/snprintf.c"
-#endif
 
 
 static void default_warn_handler(const char *message);
