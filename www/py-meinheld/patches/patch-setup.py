$NetBSD: patch-setup.py,v 1.3 2017/11/28 12:47:28 wiz Exp $

Add NetBSD support.
https://github.com/mopemope/meinheld/pull/89

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
 
