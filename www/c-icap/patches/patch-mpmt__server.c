$NetBSD: patch-mpmt__server.c,v 1.1 2015/06/02 20:02:45 joerg Exp $

--- mpmt_server.c.orig	2015-05-28 20:06:15.000000000 +0000
+++ mpmt_server.c
@@ -55,7 +55,7 @@ extern int MIN_FREE_SERVERS;
 extern int MAX_FREE_SERVERS;
 extern int MAX_REQUESTS_BEFORE_REALLOCATE_MEM;
 extern int MAX_REQUESTS_PER_CHILD;
-extern struct ci_server_conf CONF;
+extern struct ci_server_conf ci_CONF;
 
 typedef struct server_decl {
      int srv_id;
@@ -1035,11 +1035,11 @@ int start_server()
      char command_buffer[COMMANDS_BUFFER_SIZE];
      int user_informed = 0;
 
-     ctl_socket = ci_named_pipe_create(CONF.COMMANDS_SOCKET);
+     ctl_socket = ci_named_pipe_create(ci_CONF.COMMANDS_SOCKET);
      if (ctl_socket < 0) {
           ci_debug_printf(1,
                           "Error opening control socket %s. Fatal error, exiting!\n",
-                          CONF.COMMANDS_SOCKET);
+                          ci_CONF.COMMANDS_SOCKET);
           exit(0);
      }
 
@@ -1077,7 +1077,7 @@ int start_server()
                }
                if (ret < 0) {  /*Eof received on pipe. Going to reopen ... */
                     ci_named_pipe_close(ctl_socket);
-                    ctl_socket = ci_named_pipe_open(CONF.COMMANDS_SOCKET);
+                    ctl_socket = ci_named_pipe_open(ci_CONF.COMMANDS_SOCKET);
                     if (ctl_socket < 0) {
                          ci_debug_printf(1,
                                          "Error opening control socket. We are unstable and going down!");
