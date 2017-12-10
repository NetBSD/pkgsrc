$NetBSD: patch-setup.py,v 1.1 2017/12/10 16:36:31 adam Exp $

Allow newer versions of py-confusable_homoglyphs.

--- setup.py.orig	2017-12-10 16:29:14.000000000 +0000
+++ setup.py
@@ -62,6 +62,6 @@ setup(name='django-registration',
           'Topic :: Utilities'],
       install_requires=[
           'Django>=1.8,!=1.9.*',
-          'confusable_homoglyphs~=2.0',
+          'confusable_homoglyphs>=2.0',
       ],
 )
