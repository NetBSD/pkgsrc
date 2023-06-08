$NetBSD: patch-src_3rdparty_chromium_components_resources_protobufs_binary__proto__generator.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/components/resources/protobufs/binary_proto_generator.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/components/resources/protobufs/binary_proto_generator.py
@@ -8,6 +8,7 @@
 
 """
 
+from __future__ import print_function
 import abc
 import imp
 import optparse
@@ -196,12 +197,12 @@ class BinaryProtoGenerator:
     self._ImportProtoModules(opts.path)
 
     if not self.VerifyArgs(opts):
-      print "Wrong arguments"
+      print("Wrong arguments")
       return 1
 
     try:
       self._GenerateBinaryProtos(opts)
     except Exception as e:
-      print "ERROR: Failed to render binary version of %s:\n  %s\n%s" % (
-          opts.infile, str(e), traceback.format_exc())
+      print("ERROR: Failed to render binary version of %s:\n  %s\n%s" % (
+          opts.infile, str(e), traceback.format_exc()))
       return 1
