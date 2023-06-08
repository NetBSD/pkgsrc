$NetBSD: patch-src_3rdparty_chromium_mojo_public_tools_mojom_mojom_generate_generator.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/mojo/public/tools/mojom/mojom/generate/generator.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/mojo/public/tools/mojom/mojom/generate/generator.py
@@ -136,9 +136,14 @@ class Stylizer(object):
 
 def WriteFile(contents, full_path):
   # If |contents| is same with the file content, we skip updating.
+  if not isinstance(contents, bytes):
+    data = contents.encode('utf8')
+  else:
+    data = contents
+
   if os.path.isfile(full_path):
     with open(full_path, 'rb') as destination_file:
-      if destination_file.read() == contents:
+      if destination_file.read() == data:
         return
 
   # Make sure the containing directory exists.
@@ -146,11 +151,8 @@ def WriteFile(contents, full_path):
   fileutil.EnsureDirectoryExists(full_dir)
 
   # Dump the data to disk.
-  with open(full_path, "wb") as f:
-    if not isinstance(contents, bytes):
-      f.write(contents.encode('utf-8'))
-    else:
-      f.write(contents)
+  with open(full_path, 'wb') as f:
+    f.write(data)
 
 
 def AddComputedData(module):
