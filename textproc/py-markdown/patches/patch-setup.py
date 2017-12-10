$NetBSD: patch-setup.py,v 1.3 2017/12/10 08:53:16 adam Exp $

Avoid conflicts with other python versions of this package.

--- setup.py.orig	2017-12-07 18:12:06.000000000 +0000
+++ setup.py
@@ -98,7 +98,7 @@ setup(
     maintainer_email='waylan.limberg@icloud.com',
     license='BSD License',
     packages=['markdown', 'markdown.extensions'],
-    scripts=['bin/%s' % SCRIPT_NAME],
+    scripts=['bin/%s' % SCRIPT_NAME+sys.version[0:3]],
     cmdclass={
         'install_scripts': md_install_scripts
     },
