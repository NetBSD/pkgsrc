$NetBSD: patch-uwsgiconfig.py,v 1.8 2014/01/23 14:47:05 wiz Exp $

Disable inclusion of certain packages by default. Use options framework instead.

--- uwsgiconfig.py.orig	2013-12-30 08:44:59.000000000 +0000
+++ uwsgiconfig.py
@@ -68,6 +68,7 @@ report = {
     'timer': False,
     'filemonitor': False,
     'pcre': False,
+    'uuid': False,
     'routing': False,
     'capabilities': False,
     'yaml': False,
@@ -734,7 +735,7 @@ class uConf(object):
         if 'UWSGI_PROFILE_OVERRIDE' in os.environ:
             for item in os.environ['UWSGI_PROFILE_OVERRIDE'].split(';'):
                 k,v = item.split('=', 2)
-                uc.set(k, v)
+                self.set(k, v)
 
         if 'UWSGI_AS_LIB' in os.environ:
             self.set('as_shared_library', 'true')
@@ -816,6 +817,8 @@ class uConf(object):
         if locking_mode == 'auto':
             if uwsgi_os == 'Linux' or uwsgi_os == 'SunOS':
                 locking_mode = 'pthread_mutex'
+            elif uwsgi_os == 'NetBSD':
+                locking_mode = 'posix_sem';
             # FreeBSD umtx is still not ready for process shared locking
             # starting from FreeBSD 9 posix semaphores can be shared between processes
             elif uwsgi_os in ('FreeBSD', 'GNU/kFreeBSD'):
@@ -1019,10 +1022,11 @@ class uConf(object):
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
