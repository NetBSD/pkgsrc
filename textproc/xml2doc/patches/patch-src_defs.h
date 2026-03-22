$NetBSD: patch-src_defs.h,v 1.1 2026/03/22 13:11:38 nia Exp $

Fix implicit declaration of malloc(3), exit(3), atoi(3), etc.

--- src/defs.h.orig	2026-03-22 12:49:00.807924739 +0000
+++ src/defs.h
@@ -2,6 +2,7 @@
 #define _INCLUDE_DEFS_H_
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 #ifdef WITH_PDF
