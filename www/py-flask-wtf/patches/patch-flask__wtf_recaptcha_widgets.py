$NetBSD: patch-flask__wtf_recaptcha_widgets.py,v 1.1 2013/08/04 14:58:42 kleink Exp $

--- flask_wtf/recaptcha/widgets.py.orig	2013-07-04 03:56:53.000000000 +0200
+++ flask_wtf/recaptcha/widgets.py
@@ -14,7 +14,7 @@ from werkzeug import url_encode
 try:
     from flaskext.babel import gettext as _
 except ImportError:
-    _ = lambda(s): s
+    _ = lambda s: s
 
 RECAPTCHA_API_SERVER = 'http://api.recaptcha.net/'
 RECAPTCHA_SSL_API_SERVER = 'https://www.google.com/recaptcha/api/'
