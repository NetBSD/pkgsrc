$NetBSD: patch-uwsgiconfig.py,v 1.1 2012/01/08 04:06:35 sbd Exp $

Find include/uuid/uuid.h and lib/libuuid.so under the BUILDLINK_DIR.

--- uwsgiconfig.py.orig	2011-09-11 05:54:27.000000000 +0000
+++ uwsgiconfig.py
@@ -443,10 +443,11 @@ class uConf(object):
         has_json = False
         has_uuid = False
 
-        if os.path.exists('/usr/include/uuid/uuid.h') or os.path.exists('/usr/local/include/uuid/uuid.h'):
+	BUILDLINK_DIR = os.environ.get('BUILDLINK_DIR', '/nonexistant')
+        if os.path.exists('%s/include/uuid/uuid.h' % BUILDLINK_DIR):
             has_uuid = True
             self.cflags.append("-DUWSGI_UUID")
-            if os.path.exists('/usr/lib/libuuid.so') or os.path.exists('/usr/local/lib/libuuid.so') or os.path.exists('/usr/lib64/libuuid.so') or os.path.exists('/usr/local/lib64/libuuid.so'):
+            if os.path.exists('%s/lib/libuuid.so' % BUILDLINK_DIR):
                 self.libs.append('-luuid')
 
         if self.get('append_version'):
