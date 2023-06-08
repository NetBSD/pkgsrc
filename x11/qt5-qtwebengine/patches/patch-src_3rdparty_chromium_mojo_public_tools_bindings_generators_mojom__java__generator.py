$NetBSD: patch-src_3rdparty_chromium_mojo_public_tools_bindings_generators_mojom__java__generator.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/mojo/public/tools/bindings/generators/mojom_java_generator.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/mojo/public/tools/bindings/generators/mojom_java_generator.py
@@ -25,6 +25,10 @@ sys.path.append(os.path.join(os.path.dir
                              'build', 'android', 'gyp'))
 from util import build_utils
 
+# TODO(crbug.com/1174969): Remove this once Python2 is obsoleted.
+if sys.version_info.major != 2:
+  basestring = str
+  long = int
 
 GENERATOR_PREFIX = 'java'
 
