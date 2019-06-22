$NetBSD: patch-uitoolkit_ui__event__source.c,v 1.1 2019/06/22 04:27:54 tsutsui Exp $

- pull upstream fix for 3.8.8:
 https://sourceforge.net/projects/mlterm/files/01release/mlterm-3.8.8/mlterm-3.8.8-fixes.patch
 https://bitbucket.org/arakiken/mlterm/commits/1a4368580a3a2a6239bfde5a7829645767ae0fa9
 > Fix https://sourceforge.net/p/mlterm/mailman/message/36633222/
 >  [Mlterm-dev-en] mlterm 3.8.8 slow exit

--- uitoolkit/ui_event_source.c.orig	2019-03-31 13:10:47.000000000 +0000
+++ uitoolkit/ui_event_source.c
@@ -8,7 +8,6 @@
 #include <string.h>       /* memset/memcpy */
 #include <sys/time.h>     /* timeval */
 #include <unistd.h>       /* select */
-#include <errno.h>
 #include <pobl/bl_file.h> /* bl_file_set_cloexec */
 #endif
 
@@ -169,16 +168,14 @@ static void receive_next_event(void) {
 #endif
     if ((ret = select(maxfd + 1, &read_fds, NULL, NULL, &tval)) != 0) {
       if (ret < 0) {
-        if (errno != EINTR) {
 #ifdef DEBUG
-          bl_debug_printf(BL_DEBUG_TAG " error happened in select.\n");
+        bl_debug_printf(BL_DEBUG_TAG " error happened in select.\n");
 #endif
 
-          return;
-        }
-      } else {
-        break;
+        return;
       }
+
+      break;
     }
 
 #ifdef KEY_REPEAT_BY_MYSELF
