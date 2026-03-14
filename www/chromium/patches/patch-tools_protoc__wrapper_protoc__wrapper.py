$NetBSD: patch-tools_protoc__wrapper_protoc__wrapper.py,v 1.16 2026/03/14 12:40:43 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/protoc_wrapper/protoc_wrapper.py.orig	2026-03-11 22:12:25.000000000 +0000
+++ tools/protoc_wrapper/protoc_wrapper.py
@@ -227,15 +227,19 @@ def main(argv):
     if not options.exclude_imports:
       protoc_cmd += ["--include_imports"]
 
+  nenv = os.environ.copy()
+#  nenv["PATH"] = "${WRKOBJDIR}/bin:" + nenv["PATH"]
+  nenv["LD_LIBRARY_PATH"] = "@WRKSRC@/out/Release"
+
   dependency_file_data = None
   if options.descriptor_set_out and options.descriptor_set_dependency_file:
     protoc_cmd += ['--dependency_out', options.descriptor_set_dependency_file]
-    ret = subprocess.call(protoc_cmd)
+    ret = subprocess.call(protoc_cmd, env=nenv)
 
     with open(options.descriptor_set_dependency_file, 'rb') as f:
       dependency_file_data = f.read().decode('utf-8')
 
-  ret = subprocess.call(protoc_cmd)
+  ret = subprocess.call(protoc_cmd, env=nenv)
   if ret != 0:
     if ret <= -100:
       # Windows error codes such as 0xC0000005 and 0xC0000409 are much easier to
