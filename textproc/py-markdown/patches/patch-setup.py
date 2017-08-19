$NetBSD: patch-setup.py,v 1.2 2017/08/19 14:25:15 adam Exp $

Avoid conflicts with other python versions of this package.

--- setup.py.orig	2017-08-18 00:07:03.000000000 +0000
+++ setup.py
@@ -246,7 +246,7 @@ setup(
     maintainer_email='waylan.limberg@icloud.com',
     license='BSD License',
     packages=['markdown', 'markdown.extensions'],
-    scripts=['bin/%s' % SCRIPT_NAME],
+    scripts=['bin/%s' % SCRIPT_NAME+sys.version[0:3]],
     cmdclass={
         'install_scripts': md_install_scripts,
         'build_docs': build_docs,
