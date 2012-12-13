$NetBSD: patch-src_child.c,v 1.1 2012/12/13 09:01:26 wiz Exp $

Fix CVE-2012-3505 using Debian patch.

--- src/child.c.orig	2010-01-10 22:52:04.000000000 +0000
+++ src/child.c
@@ -20,6 +20,9 @@
  * processing incoming connections.
  */
 
+#include <stdlib.h>
+#include <time.h>
+
 #include "main.h"
 
 #include "child.h"
@@ -196,6 +199,7 @@ static void child_main (struct child_s *
         }
 
         ptr->connects = 0;
+	srand(time(NULL));
 
         while (!config.quit) {
                 ptr->status = T_WAITING;
