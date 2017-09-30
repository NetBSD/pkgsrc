$NetBSD: patch-setup.py,v 1.1 2017/09/30 12:51:57 wiz Exp $

Add NetBSD support.

--- setup.py.orig	2016-11-01 23:46:07.000000000 +0000
+++ setup.py
@@ -41,6 +41,8 @@ def get_picoev_file():
         poller_file = 'meinheld/server/picoev_kqueue.c'
     elif "FreeBSD" == platform.system():
         poller_file = 'meinheld/server/picoev_kqueue.c'
+    elif "NetBSD" == platform.system():
+        poller_file = 'meinheld/server/picoev_kqueue.c'
     else:
         print("Sorry, not support .")
         sys.exit(1)
