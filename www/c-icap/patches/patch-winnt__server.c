$NetBSD: patch-winnt__server.c,v 1.1 2015/06/12 23:39:11 taca Exp $

Avoid CONF name colision.

--- winnt_server.c.orig	2013-12-27 15:08:30.000000000 +0000
+++ winnt_server.c
@@ -62,7 +62,7 @@ TCHAR *C_ICAP_CMD = TEXT("c-icap.exe -c"
 extern int KEEPALIVE_TIMEOUT;
 extern int MAX_SECS_TO_LINGER;
 extern int MAX_REQUESTS_BEFORE_REALLOCATE_MEM;
-extern struct ci_server_conf CONF;
+extern struct ci_server_conf ciCONF;
 ci_socket LISTEN_SOCKET;
 
 #define hard_close_connection(connection)  ci_hard_close(connection->fd)
@@ -340,11 +340,11 @@ void child_main(ci_socket sockfd)
 
 
      threads_list =
-         (server_decl_t **) malloc((CONF.THREADS_PER_CHILD + 1) *
+         (server_decl_t **) malloc((ciCONF.THREADS_PER_CHILD + 1) *
                                    sizeof(server_decl_t *));
-     con_queue = init_queue(CONF.THREADS_PER_CHILD);
+     con_queue = init_queue(ciCONF.THREADS_PER_CHILD);
 
-     for (i = 0; i < CONF.THREADS_PER_CHILD; i++) {
+     for (i = 0; i < ciCONF.THREADS_PER_CHILD; i++) {
           if ((threads_list[i] = newthread(con_queue)) == NULL) {
                exit(-1);        // FATAL error.....
           }
@@ -352,7 +352,7 @@ void child_main(ci_socket sockfd)
                                      (void *(*)(void *)) thread_main,
                                      (void *) threads_list[i]);
      }
-     threads_list[CONF.THREADS_PER_CHILD] = NULL;
+     threads_list[ciCONF.THREADS_PER_CHILD] = NULL;
      ci_debug_printf(1, "Threads created ....\n");
      retcode = ci_thread_create(&worker_thread,
                                 (void *(*)(void *)) worker_main,
@@ -614,7 +614,7 @@ int do_child()
      }
      ci_debug_printf(1, "Shared memory attached....\n");
      child_data =
-         register_child(&childs_queue, child_handle, CONF.THREADS_PER_CHILD,
+         register_child(&childs_queue, child_handle, ciCONF.THREADS_PER_CHILD,
                         parent_pipe);
      ci_debug_printf(1, "child registered ....\n");
 
@@ -751,14 +751,14 @@ int start_server()
      ci_proc_mutex_init(&accept_mutex);
      ci_thread_mutex_init(&control_process_mtx);
 
-     if (!create_childs_queue(&childs_queue, CONF.MAX_SERVERS)) {
+     if (!create_childs_queue(&childs_queue, ciCONF.MAX_SERVERS)) {
           log_server(NULL, "Can't init shared memory.Fatal error, exiting!\n");
           ci_debug_printf(1,
                           "Can't init shared memory.Fatal error, exiting!\n");
           exit(0);
      }
 
-     for (i = 0; i < CONF.START_SERVERS + 2; i++) {
+     for (i = 0; i < ciCONF.START_SERVERS + 2; i++) {
           child_handle = start_child(LISTEN_SOCKET);
      }
 
@@ -777,12 +777,12 @@ int start_server()
                           "Server stats: \n\t Children:%d\n\t Free servers:%d\n\tUsed servers:%d\n\tRequests served:%d\n",
                           childs, freeservers, used, maxrequests);
 
-          if ((freeservers <= CONF.MIN_SPARE_THREADS && childs < CONF.MAX_SERVERS)
-              || childs < CONF.START_SERVERS) {
+          if ((freeservers <= ciCONF.MIN_SPARE_THREADS && childs < ciCONF.MAX_SERVERS)
+              || childs < ciCONF.START_SERVERS) {
                ci_debug_printf(1, "Going to start a child .....\n");
                child_handle = start_child(LISTEN_SOCKET);
           }
-          else if (freeservers >= CONF.MAX_SPARE_THREADS && childs > CONF.START_SERVERS) {
+          else if (freeservers >= ciCONF.MAX_SPARE_THREADS && childs > ciCONF.START_SERVERS) {
                ci_thread_mutex_lock(&control_process_mtx);
                if ((child_indx = find_an_idle_child(&childs_queue)) < 0)
                     continue;
@@ -794,7 +794,7 @@ int start_server()
           }
      }
 /*
-     for(i=0;i<CONF.START_SERVERS;i++){
+     for(i=0;i<ciCONF.START_SERVERS;i++){
 	  pid=wait(&status);
 	  ci_debug_printf(1,"The child %d died with status %d\n",pid,status);
      }
@@ -804,7 +804,7 @@ int start_server()
 #else
      child_data = (child_shared_data_t *) malloc(sizeof(child_shared_data_t));
      child_data->pid = 0;
-     child_data->freeservers = CONF.THREADS_PER_CHILD;
+     child_data->freeservers = ciCONF.THREADS_PER_CHILD;
      child_data->usedservers = 0;
      child_data->requests = 0;
      child_data->connections = 0;
