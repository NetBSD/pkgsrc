$NetBSD: patch-aserver.c,v 1.2 2015/06/12 23:39:11 taca Exp $

Avoid CONF name colision.

--- aserver.c.orig	2013-12-27 15:10:53.000000000 +0000
+++ aserver.c
@@ -125,9 +125,9 @@ int main(int argc, char **argv)
      ci_txt_template_set_dir(DATADIR"templates");
      commands_init();
 
-     if (!(CONF.MAGIC_DB = ci_magic_db_load(CONF.magics_file))) {
+     if (!(ci_CONF.MAGIC_DB = ci_magic_db_load(ci_CONF.magics_file))) {
           ci_debug_printf(1, "Can not load magic file %s!!!\n",
-                          CONF.magics_file);
+                          ci_CONF.magics_file);
      }
      init_conf_tables();
      request_stats_init();
@@ -143,22 +143,22 @@ int main(int argc, char **argv)
      }
 
 #if ! defined(_WIN32)
-     if (is_icap_running(CONF.PIDFILE)) {
+     if (is_icap_running(ci_CONF.PIDFILE)) {
           ci_debug_printf(1, "c-icap server already running!\n");
           exit(-1);
      }
      if (DAEMON_MODE)
           run_as_daemon();
-     if (!set_running_permissions(CONF.RUN_USER, CONF.RUN_GROUP))
+     if (!set_running_permissions(ci_CONF.RUN_USER, ci_CONF.RUN_GROUP))
           exit(-1);
-     store_pid(CONF.PIDFILE);
+     store_pid(ci_CONF.PIDFILE);
 #endif
 
-     if (!init_server(CONF.ADDRESS, CONF.PORT, &(CONF.PROTOCOL_FAMILY)))
+     if (!init_server(ci_CONF.ADDRESS, ci_CONF.PORT, &(ci_CONF.PROTOCOL_FAMILY)))
           return -1;
      post_init_modules();
      post_init_services();
      start_server();
-     clear_pid(CONF.PIDFILE);
+     clear_pid(ci_CONF.PIDFILE);
      return 0;
 }
