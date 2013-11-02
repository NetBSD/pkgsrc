$NetBSD: patch-x11vnc_unixpw.c,v 1.1 2013/11/02 07:32:28 obache Exp $

* Use openpty(3) if available

--- x11vnc/unixpw.c.orig	2011-08-10 22:31:32.000000000 +0000
+++ x11vnc/unixpw.c
@@ -92,6 +92,18 @@ extern char *crypt(const char*, const ch
 #define IS_BSD
 #endif
 
+#if LIBVNCSERVER_HAVE_OPENPTY
+#if LIBVNCSERVER_HAVE_UTIL_H
+#include <util.h>
+#endif
+#if LIBVNCSERVER_HAVE_LIBUTIL_H
+#include <libutil.h>
+#endif
+#if LIBVNCSERVER_HAVE_PTY_H
+#include <pty.h>
+#endif
+#endif
+
 int white_pixel(void);
 void unixpw_screen(int init);
 void unixpw_keystroke(rfbBool down, rfbKeySym keysym, int init);
@@ -581,6 +593,23 @@ char *get_pty_ptmx(int *fd_p) {
 #endif /* GRANTPT */
 }
 
+#if LIBVNCSERVER_HAVE_OPENPTY
+char *get_pty_openpty(int *fd_p) {
+	int fd, sfd;
+
+	*fd_p = -1;
+
+	if (openpty(&fd, &sfd, slave_str, NULL, NULL) < 0) {
+		return NULL;
+	}
+
+#if LIBVNCSERVER_HAVE_SYS_IOCTL_H && defined(TIOCFLUSH)
+	ioctl(fd, TIOCFLUSH, (char *) 0);
+#endif
+	*fd_p = fd;
+	return slave_str;
+}
+#endif
 
 char *get_pty_loop(int *fd_p) {
 	char master_str[16];
@@ -625,6 +654,9 @@ char *get_pty(int *fd_p) {
 	if (getenv("BSD_PTY")) {
 		return get_pty_loop(fd_p);
 	}
+#if LIBVNCSERVER_HAVE_OPENPTY
+	return get_pty_openpty(fd_p);
+#else
 #ifdef IS_BSD
 	return get_pty_loop(fd_p);
 #else
@@ -635,6 +667,7 @@ char *get_pty(int *fd_p) {
 	return get_pty_loop(fd_p);
 #endif
 #endif
+#endif
 }
 
 void try_to_be_nobody(void) {
