$NetBSD: patch-binary__database__files_tests_tests.py,v 1.1 2020/08/18 14:27:16 joerg Exp $

1df96f9f7caf621c4c0d94bc09b27584e1c5aa9d

--- binary_database_files/tests/tests.py.orig	2020-08-10 14:31:32.000000000 +0000
+++ binary_database_files/tests/tests.py
@@ -313,12 +313,7 @@ class DatabaseFilesTestCase(TestCase):
         self.assertTrue(t1.upload.storage.exists(t1.upload.name))
         os.remove(t1.upload.path)
         self.assertTrue(t1.upload.storage.exists(t1.upload.name))
-        self.assertEqual(
-            t1.upload.path, os.path.join(t1.upload.storage.location, "dummy.txt")
-        )
-        self.assertEqual(
-            t1.upload.path, Location1Thing.objects.get(pk=t1.pk).upload.path
-        )
+        self.assertRaises(NotImplementedError, lambda t1: t1.upload.path, t1)
         data2 = b"22222222"
         open(os.path.join(tmpdir, "dummy.txt"), "wb").write(data2)
         t2 = Location2Thing.objects.create(
@@ -326,13 +321,7 @@ class DatabaseFilesTestCase(TestCase):
         )
         os.remove(t2.upload.path)
         self.assertTrue(t2.upload.storage.exists(t2.upload.name))
-        self.assertEqual(
-            t2.upload.path, os.path.join(t2.upload.storage.location, "dummy.txt")
-        )
-        self.assertEqual(
-            t2.upload.path, Location2Thing.objects.get(pk=t2.pk).upload.path
-        )
-
+        self.assertRaises(NotImplementedError, lambda t2: t2.upload.path, t2)
         self.assertEqual(File.objects.count(), 2)
         self.assertEqual(Location2Thing.objects.get(pk=t2.pk).upload.file.read(), data2)
         self.assertEqual(Location1Thing.objects.get(pk=t1.pk).upload.file.read(), data1)
