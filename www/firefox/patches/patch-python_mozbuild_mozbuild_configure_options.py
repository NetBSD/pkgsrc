$NetBSD: patch-python_mozbuild_mozbuild_configure_options.py,v 1.1 2016/08/06 08:46:59 ryoon Exp $

* Allow lowercase environmental variables

--- python/mozbuild/mozbuild/configure/options.py.orig	2016-07-25 20:22:07.000000000 +0000
+++ python/mozbuild/mozbuild/configure/options.py
@@ -141,9 +141,6 @@ class Option(object):
             if not isinstance(env, types.StringTypes):
                 raise InvalidOptionError(
                     'Environment variable name must be a string')
-            if not env.isupper():
-                raise InvalidOptionError(
-                    'Environment variable name must be all uppercase')
         if nargs not in (None, '?', '*', '+') and not (
                 isinstance(nargs, int) and nargs >= 0):
             raise InvalidOptionError(
@@ -250,9 +247,6 @@ class Option(object):
             if name.startswith('-'):
                 raise InvalidOptionError(
                     'Option must start with two dashes instead of one')
-            if name.islower():
-                raise InvalidOptionError(
-                    'Environment variable name must be all uppercase')
         return '', name, values
 
     @staticmethod
