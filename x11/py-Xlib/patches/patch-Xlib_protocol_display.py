$NetBSD: patch-Xlib_protocol_display.py,v 1.2 2011/09/06 20:45:05 wiz Exp $

Python-3.1 compatibility.
https://sourceforge.net/tracker/?func=detail&aid=3405244&group_id=10350&atid=310350

--- Xlib/protocol/display.py.orig	2007-06-10 14:11:58.000000000 +0000
+++ Xlib/protocol/display.py
@@ -504,7 +504,7 @@ class Display:
 
             # Ignore errors caused by a signal recieved while blocking.
             # All other errors are re-raised.
-            except select.error, err:
+            except select.error as err:
                 if err[0] != errno.EINTR:
                     raise err
 
@@ -519,7 +519,7 @@ class Display:
             if ws:
                 try:
                     i = self.socket.send(self.data_send)
-                except socket.error, err:
+                except socket.error as err:
                     self.close_internal('server: %s' % err[1])
                     raise self.socket_error
 
@@ -535,7 +535,7 @@ class Display:
                 if recieving:
                     try:
                         bytes_recv = self.socket.recv(2048)
-                    except socket.error, err:
+                    except socket.error as err:
                         self.close_internal('server: %s' % err[1])
                         raise self.socket_error
 
