$NetBSD: patch-third__party_python_futures_concurrent_futures_process.py,v 1.1 2017/08/10 14:46:15 ryoon Exp $

--- third_party/python/futures/concurrent/futures/process.py.orig	2017-07-31 16:20:49.000000000 +0000
+++ third_party/python/futures/concurrent/futures/process.py
@@ -247,7 +247,11 @@ def _check_system_limits():
     _system_limits_checked = True
     try:
         import os
-        nsems_max = os.sysconf("SC_SEM_NSEMS_MAX")
+        if sys.platform.startswith('freebsd'):
+            # sem(4) confuses sysconf(3) on FreeBSD < 11.1
+            nsems_max = -1
+        else:
+            nsems_max = os.sysconf("SC_SEM_NSEMS_MAX")
     except (AttributeError, ValueError):
         # sysconf not available or setting not available
         return
