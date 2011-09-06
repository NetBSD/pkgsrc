$NetBSD: patch-Xlib_support_vms__connect.py,v 1.2 2011/09/06 20:45:05 wiz Exp $

Python-3.1 compatibility.
https://sourceforge.net/tracker/?func=detail&aid=3405244&group_id=10350&atid=310350

--- Xlib/support/vms_connect.py.orig	2007-06-10 14:11:58.000000000 +0000
+++ Xlib/support/vms_connect.py
@@ -62,7 +62,7 @@ def get_socket(dname, host, dno):
         s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
         s.connect((host, 6000 + dno))
 
-    except socket.error, val:
+    except socket.error as val:
         raise error.DisplayConnectionError(dname, str(val))
 
     return s
