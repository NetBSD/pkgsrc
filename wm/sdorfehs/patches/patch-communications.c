$NetBSD: patch-communications.c,v 1.3 2026/03/08 12:50:48 pin Exp $

Rename local variables to avoid name clash on SunOS.

--- communications.c.orig	2026-03-08 12:35:21.063208852 +0000
+++ communications.c
@@ -49,27 +49,27 @@ listen_for_commands(void)
 void
 listen_for_commands(void)
 {
-	struct sockaddr_un sun;
+	struct sockaddr_un lsun;
 
 	if ((rp_glob_screen.control_socket_fd = socket(AF_UNIX,
 	    SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, 0)) == -1)
 		err(1, "socket");
 
-	if (strlen(rp_glob_screen.control_socket_path) >= sizeof(sun.sun_path))
+	if (strlen(rp_glob_screen.control_socket_path) >= sizeof(lsun.sun_path))
 		err(1, "control socket path too long: %s",
 		    rp_glob_screen.control_socket_path);
 
-	strncpy(sun.sun_path, rp_glob_screen.control_socket_path,
-	    sizeof(sun.sun_path)-1);
-	sun.sun_path[sizeof(sun.sun_path) - 1] = '\0';
-	sun.sun_family = AF_UNIX;
+	strncpy(lsun.sun_path, rp_glob_screen.control_socket_path,
+	    sizeof(lsun.sun_path)-1);
+	lsun.sun_path[sizeof(lsun.sun_path) - 1] = '\0';
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
@@ -186,7 +186,7 @@ send_command(int interactive, char *cmd)
 int
 send_command(int interactive, char *cmd)
 {
-	struct sockaddr_un sun;
+	struct sockaddr_un lsun;
 	char *wcmd, *response;
 	char success = 0;
 	ssize_t len;
@@ -207,16 +207,16 @@ send_command(int interactive, char *cmd)
 	if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)
 		err(1, "socket");
 
-	if (strlen(rp_glob_screen.control_socket_path) >= sizeof(sun.sun_path))
+	if (strlen(rp_glob_screen.control_socket_path) >= sizeof(lsun.sun_path))
 		err(1, "control socket path too long: %s",
 		    rp_glob_screen.control_socket_path);
 
-	strncpy(sun.sun_path, rp_glob_screen.control_socket_path,
-	    sizeof(sun.sun_path)-1);
-	sun.sun_path[sizeof(sun.sun_path) - 1] = '\0';
-	sun.sun_family = AF_UNIX;
+	strncpy(lsun.sun_path, rp_glob_screen.control_socket_path,
+	    sizeof(lsun.sun_path)-1);
+	lsun.sun_path[sizeof(lsun.sun_path) - 1] = '\0';
+	lsun.sun_family = AF_UNIX;
 
-	if (connect(fd, (struct sockaddr *)&sun, sizeof(sun)) == -1)
+	if (connect(fd, (struct sockaddr *)&lsun, sizeof(lsun)) == -1)
 		err(1, "failed to connect to control socket at %s",
 		    rp_glob_screen.control_socket_path);
 
