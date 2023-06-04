$NetBSD: patch-mailman__web_settings_base.py,v 1.1 2023/06/04 03:42:22 markd Exp $

configure paths

--- mailman_web/settings/base.py.orig	2022-09-10 14:41:36.000000000 +0000
+++ mailman_web/settings/base.py
@@ -4,7 +4,7 @@ from django.contrib.messages import cons
 from pathlib import Path
 
 #: The base directory for logs and database.
-BASE_DIR = Path('/opt/mailman/web')
+BASE_DIR = Path('@VARBASE@/lib/mailman-web')
 
 #: Default list of admins who receive the emails from error logging.
 ADMINS = (
@@ -137,7 +137,7 @@ WSGI_APPLICATION = 'mailman_web.wsgi.app
 DATABASES = {
     'default': {
         'ENGINE': 'django.db.backends.sqlite3',
-        'NAME': os.path.join(BASE_DIR, 'mailman-web.db'),
+        'NAME': os.path.join(BASE_DIR, 'data/mailman-web.db'),
         'HOST': '',
         'PORT': '',
     }
@@ -255,7 +255,7 @@ LOGGING = {
         'file': {
             'level': 'INFO',
             'class': 'logging.handlers.WatchedFileHandler',
-            'filename': os.path.join(BASE_DIR, 'logs', 'mailmanweb.log'),
+            'filename': '@VARBASE@/log/mailman-web/mailman-web.log',
             'formatter': 'verbose',
         },
         'console': {
