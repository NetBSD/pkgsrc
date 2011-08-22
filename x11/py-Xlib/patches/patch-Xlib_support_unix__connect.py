$NetBSD: patch-Xlib_support_unix__connect.py,v 1.1 2011/08/22 12:18:19 wiz Exp $

Python-3.1 compatibility.

--- Xlib/support/unix_connect.py.orig	2007-06-10 14:11:58.000000000 +0000
+++ Xlib/support/unix_connect.py
@@ -75,7 +75,7 @@ def get_socket(dname, host, dno):
         else:
             s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
             s.connect('/tmp/.X11-unix/X%d' % dno)
-    except socket.error, val:
+    except socket.error as val:
         raise error.DisplayConnectionError(dname, str(val))
 
     # Make sure that the connection isn't inherited in child processes
