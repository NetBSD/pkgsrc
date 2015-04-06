$NetBSD: patch-uwsgiconfig.py,v 1.10 2015/04/06 02:35:54 rodent Exp $

Disable inclusion of certain packages by default. Use options framework instead.

--- uwsgiconfig.py.orig	2015-03-17 07:34:34.000000000 +0000
+++ uwsgiconfig.py
@@ -73,6 +73,7 @@ report = {
     'timer': False,
     'filemonitor': False,
     'pcre': False,
+    'uuid': False,
     'routing': False,
     'capabilities': False,
     'yaml': False,
@@ -851,6 +852,8 @@ class uConf(object):
         if locking_mode == 'auto':
             if uwsgi_os == 'Linux' or uwsgi_os == 'SunOS':
                 locking_mode = 'pthread_mutex'
+            elif uwsgi_os == 'NetBSD':
+                locking_mode = 'posix_sem';
             # FreeBSD umtx is still not ready for process shared locking
             # starting from FreeBSD 9 posix semaphores can be shared between processes
             elif uwsgi_os in ('FreeBSD', 'GNU/kFreeBSD'):
@@ -1054,10 +1057,11 @@ class uConf(object):
             self.libs.append('-lcap')
             report['capabilities'] = True
 
-        if self.has_include('uuid/uuid.h'):
+        if self.get('uuid') and self.get('uuid') != 'false' and self.has_include('uuid/uuid.h'):
             self.cflags.append("-DUWSGI_UUID")
-            if uwsgi_os in ('Linux', 'GNU', 'GNU/kFreeBSD') or uwsgi_os.startswith('CYGWIN') or os.path.exists('/usr/lib/libuuid.so') or os.path.exists('/usr/local/lib/libuuid.so') or os.path.exists('/usr/lib64/libuuid.so') or os.path.exists('/usr/local/lib64/libuuid.so'):
+            if uwsgi_os in ('Linux', 'GNU', 'GNU/kFreeBSD') or uwsgi_os.startswith('CYGWIN') or os.path.exists('/usr/lib/libuuid.so') or os.path.exists('/usr/local/lib/libuuid.so') or os.path.exists('/usr/lib64/libuuid.so') or os.path.exists('/usr/local/lib64/libuuid.so') or os.path.exists(os.environ['PREFIX'] + '/lib/libuuid.so'):
                 self.libs.append('-luuid')
+            report['uuid'] = True
 
         if self.get('append_version'):
             if not self.get('append_version').startswith('-'):
