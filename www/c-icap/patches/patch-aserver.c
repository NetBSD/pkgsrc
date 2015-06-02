$NetBSD: patch-aserver.c,v 1.1 2015/06/02 20:02:45 joerg Exp $

--- aserver.c.orig	2015-05-28 20:06:22.000000000 +0000
+++ aserver.c
@@ -105,9 +105,9 @@ int main(int argc, char **argv)
      ci_txt_template_init();
      ci_txt_template_set_dir(DATADIR"templates");
 
-     if (!(CONF.MAGIC_DB = ci_magic_db_load(CONF.magics_file))) {
+     if (!(ci_CONF.MAGIC_DB = ci_magic_db_load(ci_CONF.magics_file))) {
           ci_debug_printf(1, "Can not load magic file %s!!!\n",
-                          CONF.magics_file);
+                          ci_CONF.magics_file);
      }
      init_conf_tables();
      request_stats_init();
@@ -118,26 +118,26 @@ int main(int argc, char **argv)
      ci_debug_printf(2, "My hostname is:%s\n", MY_HOSTNAME);
 
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
 
      if (!log_open()) {
           ci_debug_printf(1, "Can not init loggers. Exiting.....\n");
           exit(-1);
      }
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
