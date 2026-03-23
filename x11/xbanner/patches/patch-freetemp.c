$NetBSD: patch-freetemp.c,v 1.1 2026/03/23 10:50:44 nia Exp $

Fix implicit declaration of exit(3).

--- freetemp.c.orig	2026-03-23 10:30:10.069810480 +0000
+++ freetemp.c
@@ -1,6 +1,7 @@
 #include "xb_config.h"
 
 #include <stdio.h>
+#include <stdlib.h>
 #ifndef vms
 #include <unistd.h>
 #else
