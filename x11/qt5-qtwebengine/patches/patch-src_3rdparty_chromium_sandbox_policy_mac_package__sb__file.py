$NetBSD: patch-src_3rdparty_chromium_sandbox_policy_mac_package__sb__file.py,v 1.1 2023/12/30 16:18:35 adam Exp $

Open files as text.

--- src/3rdparty/chromium/sandbox/policy/mac/package_sb_file.py.orig	2023-12-29 22:26:49.480429698 +0000
+++ src/3rdparty/chromium/sandbox/policy/mac/package_sb_file.py
@@ -37,14 +37,14 @@ def pack_file(argv):
   output_h_file = output_directory + '/' + input_basename + '.h'
   output_cc_file = output_directory + '/' + input_basename + '.cc'
   try:
-    with open(input_filename, 'rb') as infile:
-      with open(output_h_file, 'wb') as outfile:
+    with open(input_filename, 'r') as infile:
+      with open(output_h_file, 'w') as outfile:
         outfile.write(header)
         outfile.write(h_include)
         outfile.write(namespace)
         outfile.write(h_definition % module_name)
         outfile.write(namespace_end)
-      with open(output_cc_file, 'wb') as outfile:
+      with open(output_cc_file, 'w') as outfile:
         outfile.write(header)
         outfile.write(cc_include % module_name)
         outfile.write(namespace)
