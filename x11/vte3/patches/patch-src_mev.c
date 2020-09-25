$NetBSD: patch-src_mev.c,v 1.1 2020/09/25 08:51:41 jperkin Exp $

Add SunOS compat for cfmakeraw().

--- src/mev.c.orig	2020-05-13 09:51:07.000000000 +0000
+++ src/mev.c
@@ -364,7 +364,15 @@ main(int argc, char **argv)
 
 	original = tcattr;
 	signal(SIGINT, sigint_handler);
+#ifdef __sun
+	tcattr.c_iflag &= ~(IMAXBEL|IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
+	tcattr.c_oflag &= ~OPOST;
+	tcattr.c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
+	tcattr.c_cflag &= ~(CSIZE|PARENB);
+	tcattr.c_cflag |= CS8;
+#else
 	cfmakeraw(&tcattr);
+#endif
 	if (tcsetattr(STDIN_FILENO, TCSANOW, &tcattr) != 0) {
 		perror("tcsetattr");
 		return 1;
