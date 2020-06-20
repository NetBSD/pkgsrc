$NetBSD: patch-src_vte.cc,v 1.4 2020/06/20 16:00:07 nia Exp $

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
@@ -4052,7 +4060,7 @@ out:
         case EBUSY: /* do nothing */
                 break;
         default:
-                _vte_debug_print (VTE_DEBUG_IO, "Error reading from child: %m");
+                _vte_debug_print (VTE_DEBUG_IO, "Error reading from child: %s", strerror(errno));
                 break;
 	}
 
@@ -7655,7 +7663,7 @@ Terminal::set_size(long columns,
 		 * in case something went awry.
                  */
 		if (!pty()->set_size(rows, columns))
-			g_warning("Failed to set PTY size: %m\n");
+			g_warning("Failed to set PTY size: %s\n", strerror(errno));
 		refresh_size();
 	} else {
 		m_row_count = rows;
@@ -10074,7 +10082,7 @@ Terminal::set_pty(vte::base::Pty *new_pt
         set_size(m_column_count, m_row_count);
 
         if (!pty()->set_utf8(data_syntax() == DataSyntax::eECMA48_UTF8))
-                g_warning ("Failed to set UTF8 mode: %m\n");
+                g_warning ("Failed to set UTF8 mode: %s\n", strerror(errno));
 
         /* Open channels to listen for input on. */
         connect_pty_read();
