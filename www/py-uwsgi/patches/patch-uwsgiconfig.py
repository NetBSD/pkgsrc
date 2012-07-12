--- uwsgiconfig.py.orig	2012-05-14 06:58:20.000000000 +0100
+++ uwsgiconfig.py	2012-07-06 19:25:44.000000000 +0100
@@ -443,6 +443,8 @@
         if locking_mode == 'auto':
             if uwsgi_os == 'Linux' or uwsgi_os == 'SunOS':
                 locking_mode = 'pthread_mutex'
+	    elif uwsgi_os == 'NetBSD':
+		locking_mode = 'posix_sem';
             # FreeBSD umtx is still not ready for process shared locking
             # starting from FreeBSD 9 posix semaphores can be shared between processes
             elif uwsgi_os == 'FreeBSD':
@@ -475,7 +477,7 @@
                 if int(sun_major) >= 5:
                     if int(sun_minor) >= 10:
                         event_mode = 'port'
-            elif uwsgi_os in ('Darwin', 'FreeBSD', 'OpenBSD', 'NetBSD'):
+            elif uwsgi_os in ('Darwin', 'FreeBSD', 'OpenBSD', 'NetBSD', 'DragonFly'):
                 event_mode = 'kqueue'
 
         if event_mode == 'epoll':
@@ -579,7 +581,7 @@
         has_pcre = False
 
         # re-enable after pcre fix
-        if self.get('pcre'):
+        if self.get('pcreOFF'):
             if self.get('pcre') == 'auto':
                 pcreconf = spcall('pcre-config --libs')
                 if pcreconf:
@@ -620,7 +622,7 @@
         has_json = False
         has_uuid = False
 
-        if self.has_include('uuid/uuid.h'):
+        if False and self.has_include('uuid/uuid.h'):
             has_uuid = True
             self.cflags.append("-DUWSGI_UUID")
             if uwsgi_os == 'Linux' or os.path.exists('/usr/lib/libuuid.so') or os.path.exists('/usr/local/lib/libuuid.so') or os.path.exists('/usr/lib64/libuuid.so') or os.path.exists('/usr/local/lib64/libuuid.so'):
@@ -718,7 +720,7 @@
             self.cflags.append("-DUWSGI_INI")
             self.gcc_list.append('ini')
 
-        if self.get('yaml'):
+        if self.get('yamlOFF'):
             self.cflags.append("-DUWSGI_YAML")
             self.gcc_list.append('yaml')
             if self.get('yaml_implementation') == 'libyaml':
@@ -729,7 +731,7 @@
                     self.cflags.append("-DUWSGI_LIBYAML")
                     self.libs.append('-lyaml')
 
-        if self.get('json'):
+        if self.get('jsonOFF'):
             if self.get('json') == 'auto':
                 jsonconf = spcall("pkg-config --cflags jansson")
                 if jsonconf:
@@ -749,7 +751,7 @@
                 self.libs.append('-ljansson')
                 has_json = True
 
-        if self.get('ldap'):
+        if self.get('ldapOFF'):
             if self.get('ldap') == 'auto':
                 if self.has_include('ldap.h'):
                     self.cflags.append("-DUWSGI_LDAP")
@@ -772,7 +774,7 @@
                 self.cflags.append("-DUWSGI_SCTP")
                 self.libs.append('-lsctp')
 
-        if has_uuid and self.get('zeromq'):
+        if has_uuid and self.get('zeromqiOFF'):
             if self.get('zeromq') == 'auto':
                 if self.has_include('zmq.h'):
                     self.cflags.append("-DUWSGI_ZEROMQ")
@@ -832,7 +834,7 @@
                 self.libs.append('-lexpat')
                 self.gcc_list.append('xmlconf')
 
-        if self.get('sqlite3'):
+        if self.get('sqlite3OFF'):
             if self.get('sqlite3') == 'auto':
                 if self.has_include('sqlite3.h'):
                     self.cflags.append("-DUWSGI_SQLITE3")
