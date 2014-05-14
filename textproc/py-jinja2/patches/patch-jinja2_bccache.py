$NetBSD: patch-jinja2_bccache.py,v 1.1 2014/05/14 02:28:18 mspo Exp $

--- jinja2/bccache.py-orig	2014-05-14 02:23:49.000000000 +0000
+++ jinja2/bccache.py
@@ -16,6 +16,7 @@
 """
 from os import path, listdir
 import os
+import stat
 import sys
 import errno
 import marshal
@@ -215,7 +216,7 @@ class FileSystemBytecodeCache(BytecodeCa
 
         # On windows the temporary directory is used specific unless
         # explicitly forced otherwise.  We can just use that.
-        if os.name == 'n':
+        if os.name == 'nt':
             return tmpdir
         if not hasattr(os, 'getuid'):
             raise RuntimeError('Cannot determine safe temp directory.  You '
@@ -224,12 +225,18 @@ class FileSystemBytecodeCache(BytecodeCa
         dirname = '_jinja2-cache-%d' % os.getuid()
         actual_dir = os.path.join(tmpdir, dirname)
         try:
-            # 448 == 0700
-            os.mkdir(actual_dir, 448)
+            os.mkdir(actual_dir, stat.S_IRWXU) # 0o700
         except OSError as e:
             if e.errno != errno.EEXIST:
                 raise
 
+        actual_dir_stat = os.lstat(actual_dir)
+        if actual_dir_stat.st_uid != os.getuid() \
+                or not stat.S_ISDIR(actual_dir_stat.st_mode) \
+                or stat.S_IMODE(actual_dir_stat.st_mode) != stat.S_IRWXU:
+            raise RuntimeError('Temporary directory \'%s\' has an incorrect '
+	                       'owner, permissions, or type.' % actual_dir)
+
         return actual_dir
 
     def _get_cache_filename(self, bucket):
