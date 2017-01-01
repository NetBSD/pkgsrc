$NetBSD: patch-mozilla_python_mozbuild_mozbuild_configure_options.py,v 1.1 2017/01/01 16:14:08 ryoon Exp $

--- mozilla/python/mozbuild/mozbuild/configure/options.py.orig	2016-12-14 02:08:45.000000000 +0000
+++ mozilla/python/mozbuild/mozbuild/configure/options.py
@@ -144,9 +144,6 @@ class Option(object):
             if not isinstance(env, types.StringTypes):
                 raise InvalidOptionError(
                     'Environment variable name must be a string')
-            if not env.isupper():
-                raise InvalidOptionError(
-                    'Environment variable name must be all uppercase')
         if nargs not in (None, '?', '*', '+') and not (
                 isinstance(nargs, int) and nargs >= 0):
             raise InvalidOptionError(
@@ -257,9 +254,6 @@ class Option(object):
             if name.startswith('-'):
                 raise InvalidOptionError(
                     'Option must start with two dashes instead of one')
-            if name.islower():
-                raise InvalidOptionError(
-                    'Environment variable name must be all uppercase')
         return '', name, values
 
     @staticmethod
