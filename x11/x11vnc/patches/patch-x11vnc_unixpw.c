$NetBSD: patch-x11vnc_unixpw.c,v 1.2 2018/12/18 15:53:46 tnn Exp $

* Use openpty(3) if available

--- src/unixpw.c.orig	2018-02-04 21:43:38.000000000 +0000
+++ src/unixpw.c
@@ -92,6 +92,18 @@ extern char *crypt(const char*, const ch
 #define IS_BSD
 #endif
 
+#if HAVE_OPENPTY
+#if HAVE_UTIL_H
+#include <util.h>
+#endif
+#if HAVE_LIBUTIL_H
+#include <libutil.h>
+#endif
+#if HAVE_PTY_H
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
 
+#if HAVE_OPENPTY
+char *get_pty_openpty(int *fd_p) {
+	int fd, sfd;
+
+	*fd_p = -1;
+
+	if (openpty(&fd, &sfd, slave_str, NULL, NULL) < 0) {
+		return NULL;
+	}
+
+#if HAVE_SYS_IOCTL_H && defined(TIOCFLUSH)
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
+#if HAVE_OPENPTY
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
