$NetBSD: patch-mezzanine_core_auth__backends.py,v 1.1 2017/12/30 13:44:21 adam Exp $

Django 1.11 support.
https://github.com/stephenmcd/mezzanine/pull/1750

--- mezzanine/core/auth_backends.py.orig	2017-12-25 08:31:51.000000000 +0000
+++ mezzanine/core/auth_backends.py
@@ -24,7 +24,7 @@ class MezzanineBackend(ModelBackend):
     For signup verficiation, False is given for is_active.
     """
 
-    def authenticate(self, **kwargs):
+    def authenticate(self, *args, **kwargs):
         if kwargs:
             username = kwargs.pop("username", None)
             if username:
