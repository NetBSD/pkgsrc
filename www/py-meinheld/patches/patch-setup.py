$NetBSD: patch-setup.py,v 1.2 2017/10/13 14:51:16 jperkin Exp $

Add NetBSD support.

--- setup.py.orig	2016-11-01 23:46:07.000000000 +0000
+++ setup.py
@@ -41,6 +41,10 @@ def get_picoev_file():
         poller_file = 'meinheld/server/picoev_kqueue.c'
     elif "FreeBSD" == platform.system():
         poller_file = 'meinheld/server/picoev_kqueue.c'
+    elif "NetBSD" == platform.system():
+        poller_file = 'meinheld/server/picoev_kqueue.c'
+    elif "SunOS" == platform.system():
+        poller_file = 'meinheld/server/picoev_select.c'
     else:
         print("Sorry, not support .")
         sys.exit(1)
@@ -90,7 +94,7 @@ setup(name='meinheld',
     author_email='yutaka.matsubara@gmail.com',
     url='http://meinheld.org',
     license='BSD',
-    platforms='Linux, BSD, Darwin',
+    platforms='Linux, BSD, Darwin, SunOS',
     packages= ['meinheld'],
     install_requires=install_requires,
 
