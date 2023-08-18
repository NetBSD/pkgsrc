$NetBSD: patch-lib_viewvc.py,v 1.1 2023/08/18 22:20:49 hauke Exp $

Look for config file under PKG_SYSCONFDIR

--- lib/viewvc.py.orig	2023-01-04 14:48:34.000000000 +0000
+++ lib/viewvc.py
@@ -5158,6 +5158,7 @@ def load_config(pathname=None, server=No
   # default.
   pathname = (env_pathname
               or pathname
+              or "@PKG_SYSCONFDIR@/viewvc.conf"
               or os.path.join(os.path.dirname(os.path.dirname(__file__)),
                               "viewvc.conf"))
 
