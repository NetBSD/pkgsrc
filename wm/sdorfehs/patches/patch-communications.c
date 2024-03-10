$NetBSD: patch-communications.c,v 1.1 2024/03/10 21:02:21 vins Exp $

Rename local variables to avoid name clash on SunOS.

--- communications.c.orig	2024-03-10 19:07:49.914451195 +0000
+++ communications.c
@@ -49,26 +49,26 @@ init_control_socket_path(void)
 void
 listen_for_commands(void)
 {
-	struct sockaddr_un sun;
+	struct sockaddr_un lsun;
 
 	if ((rp_glob_screen.control_socket_fd = socket(AF_UNIX,
 	    SOCK_STREAM | SOCK_NONBLOCK, 0)) == -1)
 		err(1, "socket");
 
-	if (strlen(rp_glob_screen.control_socket_path) >= sizeof(sun.sun_path))
+	if (strlen(rp_glob_screen.control_socket_path) >= sizeof(lsun.sun_path))
 		err(1, "control socket path too long: %s",
 		    rp_glob_screen.control_socket_path);
 
-	strncpy(sun.sun_path, rp_glob_screen.control_socket_path,
-	    sizeof(sun.sun_path));
-	sun.sun_family = AF_UNIX;
+	strncpy(lsun.sun_path, rp_glob_screen.control_socket_path,
+	    sizeof(lsun.sun_path));
+	lsun.sun_family = AF_UNIX;
 
 	if (unlink(rp_glob_screen.control_socket_path) == -1 &&
 	    errno != ENOENT)
 		err(1, "unlink %s",rp_glob_screen.control_socket_path);
 
-	if (bind(rp_glob_screen.control_socket_fd, (struct sockaddr *)&sun,
-	    sizeof(sun)) == -1)
+	if (bind(rp_glob_screen.control_socket_fd, (struct sockaddr *)&lsun,
+	    sizeof(lsun)) == -1)
 		err(1, "bind %s", rp_glob_screen.control_socket_path);
 
 	if (chmod(rp_glob_screen.control_socket_path, 0600) == -1)
@@ -84,7 +84,7 @@ listen_for_commands(void)
 int
 send_command(int interactive, unsigned char *cmd)
 {
-	struct sockaddr_un sun;
+	struct sockaddr_un lsun;
 	char *wcmd, *bufstart;
 	char ret[BUFSZ+1];
 	char success = 0;
@@ -108,15 +108,15 @@ send_command(int interactive, unsigned c
 	if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)
 		err(1, "socket");
 
-	if (strlen(rp_glob_screen.control_socket_path) >= sizeof(sun.sun_path))
+	if (strlen(rp_glob_screen.control_socket_path) >= sizeof(lsun.sun_path))
 		err(1, "control socket path too long: %s",
 		    rp_glob_screen.control_socket_path);
 
-	strncpy(sun.sun_path, rp_glob_screen.control_socket_path,
-	    sizeof(sun.sun_path));
-	sun.sun_family = AF_UNIX;
+	strncpy(lsun.sun_path, rp_glob_screen.control_socket_path,
+	    sizeof(lsun.sun_path));
+	lsun.sun_family = AF_UNIX;
 
-	if (connect(fd, (struct sockaddr *)&sun, sizeof(sun)) == -1)
+	if (connect(fd, (struct sockaddr *)&lsun, sizeof(lsun)) == -1)
 		err(1, "failed to connect to control socket at %s",
 		    rp_glob_screen.control_socket_path);
 
