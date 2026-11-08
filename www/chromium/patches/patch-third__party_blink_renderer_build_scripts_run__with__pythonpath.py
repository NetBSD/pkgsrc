$NetBSD: patch-third__party_blink_renderer_build_scripts_run__with__pythonpath.py,v 1.32 2026/11/08 15:39:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/build/scripts/run_with_pythonpath.py.orig	2026-11-02 23:22:33.000000000 +0000
+++ third_party/blink/renderer/build/scripts/run_with_pythonpath.py
@@ -23,6 +23,7 @@ def main():
             (os.pathsep + env['PYTHONPATH']) if 'PYTHONPATH' in env else ''
         )
         env['PYTHONPATH'] = os.pathsep.join(python_paths) + existing_pp
+    env['LD_LIBRARY_PATH'] = "@WRKSRC@/out/Release"
     sys.exit(subprocess.call([sys.executable] + args, env=env))
 
 
