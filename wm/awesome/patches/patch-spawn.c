$NetBSD: patch-spawn.c,v 1.1 2012/08/26 20:28:17 is Exp $

--- spawn.c.orig        2012-08-20 16:48:36.000000000 +0000
+++ spawn.c
@@ -24,7 +24,7 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 
-#include <glib/gspawn.h>
+#include <glib.h>
 
 #include "spawn.h"
 #include "screen.h"

