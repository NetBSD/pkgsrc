$NetBSD: patch-xmovectrl_xmovectrl.c,v 1.1 2012/12/24 21:16:40 joerg Exp $

--- xmovectrl/xmovectrl.c.orig	2012-12-23 00:43:42.000000000 +0000
+++ xmovectrl/xmovectrl.c
@@ -15,6 +15,7 @@
  *   limitation a license to do the foregoing actions under any patents of
  *   the party supplying this software to the X Consortium.
  */
+#include <unistd.h>
 #include <stdio.h>
 #include <sys/types.h>         /* needed by sys/socket.h and netinet/in.h */
 #include <sys/socket.h>        /* for AF_INET, SOCK_STREAM, ... */
@@ -33,6 +34,8 @@ Bool littleEndian;
 int auth_namelen, auth_datalen;
 char *auth_name, *auth_data;
 
+void DoServerSetup(int server_fd);
+
 main(int argc, char **argv, char **envp)
 {
      char **cur_argv = argv + 1;
@@ -142,7 +145,7 @@ ConnectToServer()
     return(ServerFD);
 }     
 
-
+void
 DoServerSetup(int server_fd)
 {
      unsigned char iobuf[512];
