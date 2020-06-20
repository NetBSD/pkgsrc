$NetBSD: patch-src_vte.cc,v 1.3 2020/06/20 00:10:24 ryoon Exp $

Use correct includes on SunOS.
Don't use packet mode on SunOS.

--- src/vte.cc.orig	2020-05-13 09:51:07.000000000 +0000
+++ src/vte.cc
@@ -3966,6 +3966,9 @@ Terminal::pty_io_read(int const fd,
 			bp = chunk->data + chunk->len;
 			len = 0;
 			do {
+#ifdef __sun
+				int ret = read (fd, bp, rem);
+#else
                                 /* We'd like to read (fd, bp, rem); but due to TIOCPKT mode
                                  * there's an extra input byte returned at the beginning.
                                  * We need to see what that byte is, but otherwise drop it
@@ -3977,6 +3980,7 @@ Terminal::pty_io_read(int const fd,
                                 int ret = read (fd, bp - 1, rem + 1);
                                 pkt_header = bp[-1];
                                 bp[-1] = save;
+#endif
 				switch (ret){
 					case -1:
 						err = errno;
@@ -3985,12 +3989,15 @@ Terminal::pty_io_read(int const fd,
 						eos = true;
 						goto out;
 					default:
+#ifndef __sun
                                                 ret--;
-
                                                 if (pkt_header == TIOCPKT_DATA) {
+#endif
                                                         bp += ret;
                                                         rem -= ret;
                                                         len += ret;
+#ifndef __sun
+                                                ret--;
                                                 } else {
                                                         if (pkt_header & TIOCPKT_IOCTL) {
                                                                 /* We'd like to always be informed when the termios change,
@@ -4012,6 +4019,7 @@ Terminal::pty_io_read(int const fd,
                                                                 pty_scroll_lock_changed(false);
                                                         }
                                                 }
+#endif
 						break;
 				}
 			} while (rem);
