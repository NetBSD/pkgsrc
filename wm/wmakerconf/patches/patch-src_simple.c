$NetBSD: patch-src_simple.c,v 1.1 2026/01/20 08:45:15 wiz Exp $

--- src/simple.c.orig	2026-01-20 08:43:47.104569347 +0000
+++ src/simple.c
@@ -29,6 +29,7 @@
 
 #include "config.h"
 
+#include <ctype.h>
 #include <stdio.h>
 #include <stdlib.h>
 
