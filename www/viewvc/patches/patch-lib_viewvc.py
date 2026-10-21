$NetBSD: patch-lib_viewvc.py,v 1.2 2026/10/21 16:00:17 hauke Exp $

Look for config file under PKG_SYSCONFDIR

--- lib/viewvc.py.orig	2026-10-21 15:41:55.661125227 +0000
+++ lib/viewvc.py
@@ -5574,6 +5574,7 @@ def load_config(pathname=None, server=No
     pathname = (
         env_pathname
         or pathname
+        or "@PKG_SYSCONFDIR@/viewvc.conf"
         or os.path.join(os.path.dirname(os.path.dirname(__file__)), "viewvc.conf")
     )
 
