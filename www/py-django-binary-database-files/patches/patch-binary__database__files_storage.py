$NetBSD: patch-binary__database__files_storage.py,v 1.2 2020/08/19 00:29:46 joerg Exp $

1df96f9f7caf621c4c0d94bc09b27584e1c5aa9d
73cd278717a4dd9020979d6d08eb56365a728357

--- binary_database_files/storage.py.orig	2020-08-10 14:31:32.000000000 +0000
+++ binary_database_files/storage.py
@@ -12,6 +12,11 @@ from binary_database_files import utils
 from binary_database_files import settings as _settings
 
 
+class DatabaseFile(files.File):
+    def close(self):
+        pass
+
+
 class DatabaseStorage(FileSystemStorage):
     """Subclass of FileSystemStorage that implements the necessary methods to use the database for files."""
 
@@ -63,7 +68,7 @@ class DatabaseStorage(FileSystemStorage)
         fh.name = name
         fh.mode = mode
         fh.size = size
-        o = files.File(fh)
+        o = DatabaseFile(fh)
         return o
 
     def _save(self, name, content):
@@ -109,21 +109,31 @@ class DatabaseStorage(FileSystemStorage):
         full_path = safe_join(self.location, name)
         return full_path[len(root_path) + 1 :]
 
+    def _path(self, instance_name):
+        return safe_join(settings.MEDIA_ROOT, instance_name)
+
     def path(self, name):
         """
         Return a local filesystem path where the file can be retrieved using
         Python's built-in open() function.
 
         File names are normalized to the MEDIA_ROOT.
+
+        If the file has not been saved to disk, a NotImplementedError will
+        be raised.
         """
-        return safe_join(settings.MEDIA_ROOT, self.get_instance_name(name))
+        localpath = self._path(self.get_instance_name(name))
+        if not os.path.exists(localpath):
+            raise NotImplementedError
+        return localpath
 
     def exists(self, name):
         """Return True if a file with the given filename exists in the database. Return False otherwise."""
         name = self.get_instance_name(name)
         if models.File.objects.filter(name=name).exists():
             return True
-        return super(DatabaseStorage, self).exists(name)
+        localpath = self._path(name)
+        return os.path.exists(localpath)
 
     def delete(self, name):
         """Delete the file with filename `name` from the database and filesystem."""
@@ -135,7 +145,9 @@ class DatabaseStorage(FileSystemStorage):
                 os.remove(hash_fn)
         except models.File.DoesNotExist:
             pass
-        return super(DatabaseStorage, self).delete(name)
+        localpath = self._path(name)
+        if os.path.exists(localpath):
+            return super(DatabaseStorage, self).delete(name)
 
     def url(self, name):
         """Return the web-accessible URL for the file with filename `name`.
