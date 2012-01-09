$NetBSD: patch-uwsgiconfig.py,v 1.3 2012/01/09 07:08:25 sbd Exp $

Find include/uuid/uuid.h and lib/libuuid.so under the BUILDLINK_DIR.

--- uwsgiconfig.py.orig	2011-09-11 05:54:27.000000000 +0000
+++ uwsgiconfig.py
@@ -443,7 +443,7 @@ class uConf(object):
         has_json = False
         has_uuid = False
 
-        if os.path.exists('/usr/include/uuid/uuid.h') or os.path.exists('/usr/local/include/uuid/uuid.h'):
+        if False and ( os.path.exists('/usr/include/uuid/uuid.h') or os.path.exists('/usr/local/include/uuid/uuid.h')):
             has_uuid = True
             self.cflags.append("-DUWSGI_UUID")
             if os.path.exists('/usr/lib/libuuid.so') or os.path.exists('/usr/local/lib/libuuid.so') or os.path.exists('/usr/lib64/libuuid.so') or os.path.exists('/usr/local/lib64/libuuid.so'):
@@ -541,7 +541,7 @@ class uConf(object):
             self.cflags.append("-DUWSGI_INI")
             self.gcc_list.append('ini')
 
-        if self.get('yaml'):
+        if self.get('yamlOFF'):
             self.cflags.append("-DUWSGI_YAML")
             self.gcc_list.append('yaml')
             if self.get('yaml_implementation') == 'libyaml':
@@ -552,7 +552,7 @@ class uConf(object):
                     self.cflags.append("-DUWSGI_LIBYAML")
                     self.libs.append('-lyaml')
 
-        if self.get('json'):
+        if self.get('jsonOFF'):
             if self.get('json') == 'auto':
                 jsonconf = spcall("pkg-config --cflags jansson")
                 if jsonconf:
@@ -572,7 +572,7 @@ class uConf(object):
                 self.libs.append('-ljansson')
                 has_json = True
 
-        if self.get('ldap'):
+        if self.get('ldapOFF'):
             if self.get('ldap') == 'auto':
                 if os.path.exists('/usr/include/ldap.h'):
                     self.cflags.append("-DUWSGI_LDAP")
@@ -583,7 +583,7 @@ class uConf(object):
                 self.gcc_list.append('ldap')
                 self.libs.append('-lldap')
 
-        if has_uuid and self.get('zeromq'):
+        if has_uuid and self.get('zeromqOFF'):
             if self.get('zeromq') == 'auto':
                 if os.path.exists('/usr/include/zmq.h') or os.path.exists('/usr/local/include/zmq.h'):
                     self.cflags.append("-DUWSGI_ZEROMQ")
@@ -631,7 +631,7 @@ class uConf(object):
                 self.libs.append('-lexpat')
                 self.gcc_list.append('xmlconf')
 
-        if self.get('sqlite3'):
+        if self.get('sqlite3OFF'):
             if self.get('sqlite3') == 'auto':
                 if os.path.exists('/usr/include/sqlite3.h') or os.path.exists('/usr/local/include/sqlite3.h'):
                     self.cflags.append("-DUWSGI_SQLITE3")
