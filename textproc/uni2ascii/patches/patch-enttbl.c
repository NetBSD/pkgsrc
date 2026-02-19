$NetBSD: patch-enttbl.c,v 1.1 2026/02/19 15:19:19 wiz Exp $

--- enttbl.c.orig	2026-02-19 15:02:51.405490605 +0000
+++ enttbl.c
@@ -21,6 +21,7 @@
 #include "config.h"
 #include <stdlib.h>
 #include "unicode.h"
+#include <string.h>
 
 struct ent {
   char *name;
