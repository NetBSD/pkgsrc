$NetBSD: patch-src_vte.cc,v 1.2 2018/06/22 14:34:43 jperkin Exp $

Use correct includes on SunOS.
Don't use packet mode on SunOS.

--- src/vte.cc.orig	2018-05-21 19:31:53.000000000 +0000
+++ src/vte.cc
@@ -25,6 +25,9 @@
 #include <string.h>
 #include <sys/ioctl.h>
 #include <sys/param.h> /* howmany() */
+#ifdef __sun
+#include <sys/ptyvar.h>
+#endif
 #include <errno.h>
 #include <fcntl.h>
 #include <math.h>
@@ -3970,6 +3973,9 @@ VteTerminalPrivate::pty_io_read(GIOChann
 			bp = chunk->data + chunk->len;
 			len = 0;
 			do {
+#ifdef __sun
+				int ret = read (fd, bp, rem);
+#else
                                 /* We'd like to read (fd, bp, rem); but due to TIOCPKT mode
                                  * there's an extra input byte returned at the beginning.
                                  * We need to see what that byte is, but otherwise drop it
@@ -3980,6 +3986,7 @@ VteTerminalPrivate::pty_io_read(GIOChann
                                 int ret = read (fd, bp - 1, rem + 1);
                                 pkt_header = bp[-1];
                                 bp[-1] = save;
+#endif
 				switch (ret){
 					case -1:
 						err = errno;
@@ -3988,6 +3995,7 @@ VteTerminalPrivate::pty_io_read(GIOChann
 						eof = TRUE;
 						goto out;
 					default:
+#ifndef __sun
                                                 ret--;
 
                                                 if (pkt_header & TIOCPKT_IOCTL) {
@@ -4008,6 +4016,7 @@ VteTerminalPrivate::pty_io_read(GIOChann
                                                 } else if (pkt_header & TIOCPKT_START) {
                                                         pty_scroll_lock_changed(false);
                                                 }
+#endif
 
 						bp += ret;
 						rem -= ret;
