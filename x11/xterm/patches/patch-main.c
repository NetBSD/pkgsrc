$NetBSD: patch-main.c,v 1.1 2016/05/26 14:57:24 khorben Exp $

Avoid consuming 100% CPU in hold mode when the child exits.

--- main.c.orig	2016-03-11 00:31:37.000000000 +0000
+++ main.c
@@ -5213,8 +5213,7 @@ reapchild(int n GCC_UNUSED)
     do {
 	if (pid == TScreenOf(term)->pid) {
 	    DEBUG_MSG("Exiting\n");
-	    if (!hold_screen)
-		need_cleanup = True;
+	    need_cleanup = True;
 	}
     } while ((pid = nonblocking_wait()) > 0);
 
