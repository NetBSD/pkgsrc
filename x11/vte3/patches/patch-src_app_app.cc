$NetBSD: patch-src_app_app.cc,v 1.5 2022/04/05 15:51:58 jperkin Exp $

Add SunOS compat for cfmakeraw().

--- src/app/app.cc.orig	2022-03-27 17:52:19.000000000 +0000
+++ src/app/app.cc
@@ -3040,7 +3040,15 @@ main(int argc,
                struct termios tcattr;
                if (tcgetattr(STDIN_FILENO, &tcattr) == 0) {
                        saved_tcattr = tcattr;
+#ifdef __sun
+                       tcattr.c_iflag &= ~(IMAXBEL|IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
+                       tcattr.c_oflag &= ~OPOST;
+                       tcattr.c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
+                       tcattr.c_cflag &= ~(CSIZE|PARENB);
+                       tcattr.c_cflag |= CS8;
+#else
                        cfmakeraw(&tcattr);
+#endif
                        if (tcsetattr(STDIN_FILENO, TCSANOW, &tcattr) == 0)
                                reset_termios = true;
                }
