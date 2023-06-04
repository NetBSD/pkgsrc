$NetBSD: patch-mailman__web_manage.py,v 1.1 2023/06/04 03:42:22 markd Exp $

configure paths

--- mailman_web/manage.py.orig	2022-09-10 15:28:48.000000000 +0000
+++ mailman_web/manage.py
@@ -12,7 +12,7 @@ def setup():
 
     MAILMAN_WEB_CONFIG = os.getenv(
         'MAILMAN_WEB_CONFIG',
-        '/etc/mailman3/settings.py',
+        '@PKG_SYSCONFDIR@/settings.py',
     )
 
     if not os.path.exists(MAILMAN_WEB_CONFIG):
