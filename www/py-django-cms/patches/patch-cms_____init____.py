$NetBSD: patch-cms_____init____.py,v 1.1 2013/04/01 12:31:23 joerg Exp $

--- cms/__init__.py.orig	2013-03-31 16:23:04.000000000 +0000
+++ cms/__init__.py
@@ -1,12 +1,16 @@
 # -*- coding: utf-8 -*-
 __version__ = '2.3.5'
 
+import django.core.exceptions
+
 # patch settings 
 try:
     from django.conf import settings
     if 'cms' in settings.INSTALLED_APPS:
         from conf import patch_settings
         patch_settings()
+except django.core.exceptions.ImproperlyConfigured:
+    pass
 except ImportError: # pragma: no cover
     """
     This exception means that either the application is being built, or is
