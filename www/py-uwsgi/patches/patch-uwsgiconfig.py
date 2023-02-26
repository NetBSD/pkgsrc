$NetBSD: patch-uwsgiconfig.py,v 1.11 2023/02/26 00:52:49 joerg Exp $

Disable inclusion of certain packages by default. Use options framework instead.

--- uwsgiconfig.py.orig	2022-10-24 10:21:58.000000000 +0000
+++ uwsgiconfig.py
@@ -86,6 +86,7 @@ report = {
     'timer': False,
     'filemonitor': False,
     'pcre': False,
+    'uuid': False,
     'routing': False,
     'capabilities': False,
     'yaml': False,
@@ -830,10 +831,11 @@ class uConf(object):
 
         global uwsgi_version
 
-        kvm_list = ['FreeBSD', 'OpenBSD', 'NetBSD', 'DragonFly']
+        kvm_list = ['FreeBSD', 'OpenBSD', 'DragonFly']
 
         if 'UWSGI_PROFILE_OVERRIDE' in os.environ:
             for item in os.environ['UWSGI_PROFILE_OVERRIDE'].split(';'):
+                if not item: continue
                 k,v = item.split('=', 1)
                 self.set(k, v)
 
@@ -921,6 +923,8 @@ class uConf(object):
         if locking_mode == 'auto':
             if uwsgi_os == 'Linux' or uwsgi_os == 'SunOS':
                 locking_mode = 'pthread_mutex'
+            elif uwsgi_os == 'NetBSD':
+                locking_mode = 'posix_sem';
             # FreeBSD umtx is still not ready for process shared locking
             # starting from FreeBSD 9 posix semaphores can be shared between processes
             elif uwsgi_os in ('FreeBSD', 'GNU/kFreeBSD'):
@@ -1124,10 +1128,11 @@ class uConf(object):
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
