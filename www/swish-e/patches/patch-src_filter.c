$NetBSD: patch-src_filter.c,v 1.1 2026/03/16 13:55:37 nia Exp $

Fix implicit declaration of kill(2).

--- src/filter.c.orig	2026-03-16 13:36:24.658393274 +0000
+++ src/filter.c
@@ -42,6 +42,7 @@ $Id: filter.c,v 1.35 2007/01/05 22:14:10
 #include "error.h"
 #include "filter.h"
 #include <stdlib.h>
+#include <signal.h>
 
 #ifdef HAVE_WORKING_FORK
 #include <sys/types.h>
