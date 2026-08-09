$NetBSD: patch-third__party_blink_renderer_build_scripts_run__with__pythonpath.py,v 1.24 2026/08/09 06:31:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/build/scripts/run_with_pythonpath.py.orig	2026-08-05 20:17:42.000000000 +0000
+++ third_party/blink/renderer/build/scripts/run_with_pythonpath.py
@@ -22,6 +22,7 @@ def main():
         existing_pp = (
             os.pathsep + env['PYTHONPATH']) if 'PYTHONPATH' in env else ''
         env['PYTHONPATH'] = os.pathsep.join(python_paths) + existing_pp
+    env['LD_LIBRARY_PATH'] = "@WRKSRC@/out/Release"
     sys.exit(subprocess.call([sys.executable] + args, env=env))
 
 
