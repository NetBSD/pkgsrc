$NetBSD: patch-src_3rdparty_chromium_mojo_public_tools_bindings_gen__data__files__list.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/mojo/public/tools/bindings/gen_data_files_list.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/mojo/public/tools/bindings/gen_data_files_list.py
@@ -18,7 +18,6 @@ import os
 import re
 import sys
 
-from cStringIO import StringIO
 from optparse import OptionParser
 
 sys.path.insert(
@@ -41,12 +40,9 @@ def main():
   pattern = re.compile(options.pattern)
   files = [f for f in os.listdir(options.directory) if pattern.match(f)]
 
-  stream = StringIO()
-  for f in files:
-    print(f, file=stream)
+  contents = '\n'.join(f for f in files) + '\n'
+  WriteFile(contents, options.output)
 
-  WriteFile(stream.getvalue(), options.output)
-  stream.close()
 
 if __name__ == '__main__':
   sys.exit(main())
