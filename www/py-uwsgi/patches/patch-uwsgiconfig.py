$NetBSD: patch-uwsgiconfig.py,v 1.7 2014/01/05 03:46:11 rodent Exp $

--- uwsgiconfig.py.orig	2013-08-23 12:51:18.000000000 +0000
+++ uwsgiconfig.py
@@ -635,6 +635,8 @@ class uConf(object):
         if locking_mode == 'auto':
             if uwsgi_os == 'Linux' or uwsgi_os == 'SunOS':
                 locking_mode = 'pthread_mutex'
+	    elif uwsgi_os == 'NetBSD':
+		locking_mode = 'posix_sem';
             # FreeBSD umtx is still not ready for process shared locking
             # starting from FreeBSD 9 posix semaphores can be shared between processes
             elif uwsgi_os == 'FreeBSD':
@@ -672,7 +674,7 @@ class uConf(object):
                 if int(sun_major) >= 5:
                     if int(sun_minor) >= 10:
                         event_mode = 'port'
-            elif uwsgi_os in ('Darwin', 'FreeBSD', 'OpenBSD', 'NetBSD'):
+            elif uwsgi_os in ('Darwin', 'FreeBSD', 'OpenBSD', 'NetBSD', 'DragonFly'):
                 event_mode = 'kqueue'
 
         if event_mode == 'epoll':
@@ -791,7 +793,7 @@ class uConf(object):
         has_pcre = False
 
         # re-enable after pcre fix
-        if self.get('pcre'):
+        if self.get('pcreOFF'):
             if self.get('pcre') == 'auto':
                 pcreconf = spcall('pcre-config --libs')
                 if pcreconf:
@@ -854,7 +856,7 @@ class uConf(object):
         has_json = False
         has_uuid = False
 
-        if self.has_include('uuid/uuid.h'):
+        if False and self.has_include('uuid/uuid.h'):
             has_uuid = True
             self.cflags.append("-DUWSGI_UUID")
             if uwsgi_os == 'Linux' or os.path.exists('/usr/lib/libuuid.so') or os.path.exists('/usr/local/lib/libuuid.so') or os.path.exists('/usr/lib64/libuuid.so') or os.path.exists('/usr/local/lib64/libuuid.so'):
@@ -956,7 +958,7 @@ class uConf(object):
             self.gcc_list.append('core/ini')
             report['ini'] = True
 
-        if self.get('yaml'):
+        if self.get('yamlOFF'):
             self.cflags.append("-DUWSGI_YAML")
             self.gcc_list.append('core/yaml')
             report['yaml'] = True
@@ -970,7 +972,7 @@ class uConf(object):
                     self.libs.append('-lyaml')
                     report['yaml'] = 'libyaml'
 
-        if self.get('json'):
+        if self.get('jsonOFF'):
             if self.get('json') == 'auto':
                 jsonconf = spcall("pkg-config --cflags jansson")
                 if jsonconf:
@@ -993,7 +995,7 @@ class uConf(object):
         if has_json:
             report['json'] = True
 
-        if self.get('ldap'):
+        if self.get('ldapOFF'):
             if self.get('ldap') == 'auto':
                 if self.has_include('ldap.h'):
                     self.cflags.append("-DUWSGI_LDAP")
@@ -1020,7 +1022,7 @@ class uConf(object):
                 report['ssl'] = True
 
 
-        if has_uuid and self.get('zeromq'):
+        if has_uuid and self.get('zeromqOFF'):
             if self.get('zeromq') == 'auto':
                 if self.has_include('zmq.h'):
                     self.cflags.append("-DUWSGI_ZEROMQ")
@@ -1080,7 +1082,7 @@ class uConf(object):
                 self.gcc_list.append('core/xmlconf')
                 report['xml'] = 'expat'
 
-        if self.get('sqlite3'):
+        if self.get('sqlite3OFF'):
             if self.get('sqlite3') == 'auto':
                 if self.has_include('sqlite3.h'):
                     self.cflags.append("-DUWSGI_SQLITE3")
