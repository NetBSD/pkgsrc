$NetBSD: patch-ui_webui_resources_tools_minify__js.py,v 1.8 2026/09/02 13:13:40 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/webui/resources/tools/minify_js.py.orig	2026-08-31 22:47:51.000000000 +0000
+++ ui/webui/resources/tools/minify_js.py
@@ -32,7 +32,7 @@ def main(argv):
   # Spawn a NodeJS script to use the programmatic Terser API, since the CLI API
   # does not allow compressing multiple files at once. This is done to avoid
   # launching NodeJS once for every input file.
-  node.RunNode([
+  node.RunNode(['--jitless',
       os.path.join(_HERE_PATH, 'minify_js.js'), '--in_folder', in_path,
       '--out_folder', out_path
   ] + args.in_files)
