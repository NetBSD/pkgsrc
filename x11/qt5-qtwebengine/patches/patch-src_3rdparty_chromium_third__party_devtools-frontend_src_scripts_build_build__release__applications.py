$NetBSD: patch-src_3rdparty_chromium_third__party_devtools-frontend_src_scripts_build_build__release__applications.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/devtools-frontend/src/scripts/build/build_release_applications.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/devtools-frontend/src/scripts/build/build_release_applications.py
@@ -10,7 +10,7 @@ Builds applications in release mode:
 and the application loader into a single script.
 """
 
-from cStringIO import StringIO
+from io import StringIO
 from os import path
 from os.path import join
 import copy
@@ -145,8 +145,7 @@ class ReleaseBuilder(object):
             resource_content = read_file(path.join(self.application_dir, resource_name))
             if not (resource_name.endswith('.html')
                     or resource_name.endswith('md')):
-                resource_content += resource_source_url(resource_name).encode(
-                    'utf-8')
+                resource_content += resource_source_url(resource_name)
             resource_content = resource_content.replace('\\', '\\\\')
             resource_content = resource_content.replace('\n', '\\n')
             resource_content = resource_content.replace('"', '\\"')
@@ -173,7 +172,9 @@ class ReleaseBuilder(object):
     def _concatenate_application_script(self, output):
         output.write('Root.allDescriptors.push(...%s);' % self._release_module_descriptors())
         if self.descriptors.extends:
-            output.write('Root.applicationDescriptor.modules.push(...%s);' % json.dumps(self.descriptors.application.values()))
+            output.write(
+                'Root.applicationDescriptor.modules.push(...%s);' %
+                json.dumps(list(self.descriptors.application.values())))
         else:
             output.write('Root.applicationDescriptor = %s;' % self.descriptors.application_json())
 
