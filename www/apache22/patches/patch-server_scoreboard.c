$NetBSD: patch-server_scoreboard.c,v 1.1.2.2 2012/01/18 19:54:36 tron Exp $

patch for CVE-2012-0031 taken from Revision 1231058 of http://svn.apache.org/

--- server/scoreboard.c.orig	2010-10-07 16:56:54.000000000 +0000
+++ server/scoreboard.c
@@ -42,6 +42,8 @@ AP_DECLARE_DATA const char *ap_scoreboar
 AP_DECLARE_DATA int ap_extended_status = 0;
 AP_DECLARE_DATA int ap_mod_status_reqtail = 0;
 
+static ap_scoreboard_e scoreboard_type;
+
 #if APR_HAS_SHARED_MEMORY
 
 #include "apr_shm.h"
@@ -250,7 +252,7 @@ apr_status_t ap_cleanup_scoreboard(void 
     if (ap_scoreboard_image == NULL) {
         return APR_SUCCESS;
     }
-    if (ap_scoreboard_image->global->sb_type == SB_SHARED) {
+    if (scoreboard_type == SB_SHARED) {
         ap_cleanup_shared_mem(NULL);
     }
     else {
@@ -312,7 +314,7 @@ int ap_create_scoreboard(apr_pool_t *p, 
         ap_init_scoreboard(sb_mem);
     }
 
-    ap_scoreboard_image->global->sb_type = sb_type;
+    ap_scoreboard_image->global->sb_type = scoreboard_type = sb_type;
     ap_scoreboard_image->global->running_generation = 0;
     ap_scoreboard_image->global->restart_time = apr_time_now();
 
