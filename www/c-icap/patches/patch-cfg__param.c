$NetBSD: patch-cfg__param.c,v 1.1 2015/06/02 20:02:45 joerg Exp $

--- cfg_param.c.orig	2015-05-28 20:06:20.000000000 +0000
+++ cfg_param.c
@@ -38,7 +38,7 @@
 int ARGC;
 char **ARGV;
 
-struct ci_server_conf CONF = {
+struct ci_server_conf ci_CONF = {
      NULL, /* LISTEN ADDRESS */ 1344, /*PORT*/ AF_INET,    /*SOCK_FAMILY */
 #ifdef _WIN32
      "c:\\TEMP", /*TMPDIR*/ "c:\\TEMP\\c-icap.pid", /*PIDFILE*/ "\\\\.\\pipe\\c-icap",  /*COMMANDS_SOCKET; */
@@ -129,9 +129,9 @@ struct sub_table {
 };
 
 static struct ci_conf_entry conf_variables[] = {
-     {"ListenAddress", &CONF.ADDRESS, intl_cfg_set_str, NULL},
-     {"PidFile", &CONF.PIDFILE, intl_cfg_set_str, NULL},
-     {"CommandsSocket", &CONF.COMMANDS_SOCKET, intl_cfg_set_str, NULL},
+     {"ListenAddress", &ci_CONF.ADDRESS, intl_cfg_set_str, NULL},
+     {"PidFile", &ci_CONF.PIDFILE, intl_cfg_set_str, NULL},
+     {"CommandsSocket", &ci_CONF.COMMANDS_SOCKET, intl_cfg_set_str, NULL},
      {"Timeout", (void *) (&TIMEOUT), intl_cfg_set_int, NULL},
      {"KeepAlive", NULL, NULL, NULL},
      {"MaxKeepAliveRequests", &MAX_KEEPALIVE_REQUESTS, intl_cfg_set_int, NULL},
@@ -144,19 +144,19 @@ static struct ci_conf_entry conf_variabl
      {"MaxRequestsPerChild", &MAX_REQUESTS_PER_CHILD, intl_cfg_set_int, NULL},
      {"MaxRequestsReallocateMem", &MAX_REQUESTS_BEFORE_REALLOCATE_MEM,
       intl_cfg_set_int, NULL},
-     {"Port", &CONF.PORT, intl_cfg_set_int, NULL},
-     {"User", &CONF.RUN_USER, intl_cfg_set_str, NULL},
-     {"Group", &CONF.RUN_GROUP, intl_cfg_set_str, NULL},
-     {"ServerAdmin", &CONF.SERVER_ADMIN, intl_cfg_set_str, NULL},
-     {"ServerName", &CONF.SERVER_NAME, intl_cfg_set_str, NULL},
+     {"Port", &ci_CONF.PORT, intl_cfg_set_int, NULL},
+     {"User", &ci_CONF.RUN_USER, intl_cfg_set_str, NULL},
+     {"Group", &ci_CONF.RUN_GROUP, intl_cfg_set_str, NULL},
+     {"ServerAdmin", &ci_CONF.SERVER_ADMIN, intl_cfg_set_str, NULL},
+     {"ServerName", &ci_CONF.SERVER_NAME, intl_cfg_set_str, NULL},
      {"LoadMagicFile", NULL, cfg_load_magicfile, NULL},
      {"Logger", &default_logger, cfg_set_logger, NULL},
      {"ServerLog", &SERVER_LOG_FILE, intl_cfg_set_str, NULL},
      {"AccessLog", NULL, cfg_set_accesslog, NULL},
      {"LogFormat", NULL, cfg_set_logformat, NULL},
      {"DebugLevel", NULL, cfg_set_debug_level, NULL},   /*Set library's debug level */
-     {"ServicesDir", &CONF.SERVICES_DIR, intl_cfg_set_str, NULL},
-     {"ModulesDir", &CONF.MODULES_DIR, intl_cfg_set_str, NULL},
+     {"ServicesDir", &ci_CONF.SERVICES_DIR, intl_cfg_set_str, NULL},
+     {"ModulesDir", &ci_CONF.MODULES_DIR, intl_cfg_set_str, NULL},
      {"Service", NULL, cfg_load_service, NULL},
      {"ServiceAlias", NULL, cfg_service_alias, NULL},
      {"Module", NULL, cfg_load_module, NULL},
@@ -443,7 +443,7 @@ int cfg_load_magicfile(const char *direc
      }
 
      db_file = argv[0];
-     if (strcmp(CONF.magics_file, db_file) == 0) {
+     if (strcmp(ci_CONF.magics_file, db_file) == 0) {
          ci_debug_printf(2, "The db file %s is the same as default. Ignoring...\n", db_file); 
          return 1;
      }
@@ -453,8 +453,8 @@ int cfg_load_magicfile(const char *direc
           ci_debug_printf(1, "Can not load magic file %s!!!\n", db_file);
           return 0;
      }
-     if (!CONF.MAGIC_DB)
-	 CONF.MAGIC_DB = ndb;
+     if (!ci_CONF.MAGIC_DB)
+	 ci_CONF.MAGIC_DB = ndb;
 
      return 1;
 }
@@ -509,24 +509,24 @@ int cfg_set_tmp_dir(const char *directiv
           return 0;
      }
 
-     cfg_default_value_store(&CONF.TMPDIR, &CONF.TMPDIR, sizeof(char *));
+     cfg_default_value_store(&ci_CONF.TMPDIR, &ci_CONF.TMPDIR, sizeof(char *));
      len = strlen(argv[0]);
 
-     CONF.TMPDIR = ci_cfg_alloc_mem((len + 2) * sizeof(char));
-     strcpy(CONF.TMPDIR, argv[0]);
+     ci_CONF.TMPDIR = ci_cfg_alloc_mem((len + 2) * sizeof(char));
+     strcpy(ci_CONF.TMPDIR, argv[0]);
 #ifdef _WIN32
-     if (CONF.TMPDIR[len] != '\\') {
-          CONF.TMPDIR[len] = '\\';
-          CONF.TMPDIR[len + 1] = '\0';
+     if (ci_CONF.TMPDIR[len] != '\\') {
+          ci_CONF.TMPDIR[len] = '\\';
+          ci_CONF.TMPDIR[len + 1] = '\0';
      }
 #else
-     if (CONF.TMPDIR[len] != '/') {
-          CONF.TMPDIR[len] = '/';
-          CONF.TMPDIR[len + 1] = '\0';
+     if (ci_CONF.TMPDIR[len] != '/') {
+          ci_CONF.TMPDIR[len] = '/';
+          ci_CONF.TMPDIR[len + 1] = '\0';
      }
 #endif
      /*Check if tmpdir exists. If no try to build it , report an error and uses the default... */
-     CI_TMPDIR = CONF.TMPDIR;   /*Sets the library's temporary dir to .... */
+     CI_TMPDIR = ci_CONF.TMPDIR;   /*Sets the library's temporary dir to .... */
      ci_debug_printf(2, "Setting parameter :%s=%s\n", directive, argv[0]);
      return 1;
 }
@@ -814,7 +814,7 @@ int parse_file(const char *conf_file)
 /* #endif */
 
 static struct ci_options_entry options[] = {
-     {opt_pre "f", "filename", &CONF.cfg_file, ci_cfg_set_str,
+     {opt_pre "f", "filename", &ci_CONF.cfg_file, ci_cfg_set_str,
       "Specify the configuration file"},
      {opt_pre "N", NULL, &DAEMON_MODE, ci_cfg_disable, "Do not run as daemon"},
      {opt_pre "d", "level", NULL, cfg_set_debug_level_cmd,
@@ -836,7 +836,7 @@ int config(int argc, char **argv)
           ci_args_usage(argv[0], options);
           exit(-1);
      }
-     if (!parse_file(CONF.cfg_file)) {
+     if (!parse_file(ci_CONF.cfg_file)) {
           ci_debug_printf(1, "Error opening/parsing config file\n");
           exit(0);
      }
@@ -855,7 +855,7 @@ int reconfig()
                           "Error in command line options, while reconfiguring!\n");
           return 0;
      }
-     if (!parse_file(CONF.cfg_file)) {
+     if (!parse_file(ci_CONF.cfg_file)) {
           ci_debug_printf(1,
                           "Error opening/parsing config file, while reconfiguring!\n");
           return 0;
@@ -890,7 +890,7 @@ void system_shutdown()
         Release other subsystems
      */
     ci_magic_db_free();
-    CONF.MAGIC_DB = NULL;
+    ci_CONF.MAGIC_DB = NULL;
     ci_txt_template_close();
 }
 
@@ -906,9 +906,9 @@ int system_reconfigure()
 
      ci_debug_printf(1, "All resources released. Going to reload!\n");
      ci_txt_template_init();
-     if (!(CONF.MAGIC_DB = ci_magic_db_load(CONF.magics_file))) {
+     if (!(ci_CONF.MAGIC_DB = ci_magic_db_load(ci_CONF.magics_file))) {
           ci_debug_printf(1, "Can not load magic file %s!!!\n",
-                          CONF.magics_file);
+                          ci_CONF.magics_file);
      }
      init_modules();
      init_services();
@@ -917,15 +917,15 @@ int system_reconfigure()
         - Freeing all memory and resources used by configuration parameters (is it possible???)
         - reopen and read config file. Now the monitor process has now the new config parameters.
       */
-     old_port = CONF.PORT;
+     old_port = ci_CONF.PORT;
      if (!reconfig())
 	 return 0;
 
      /*
         - reinit listen socket if needed
       */
-     if (old_port != CONF.PORT) {
-          init_server(CONF.ADDRESS, CONF.PORT, &(CONF.PROTOCOL_FAMILY));
+     if (old_port != ci_CONF.PORT) {
+          init_server(ci_CONF.ADDRESS, ci_CONF.PORT, &(ci_CONF.PROTOCOL_FAMILY));
      }
 
      log_open();
