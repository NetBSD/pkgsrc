$NetBSD: patch-ui_webui_resources_tools_minify__js.py,v 1.16 2026/11/19 19:46:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/webui/resources/tools/minify_js.py.orig	2026-11-11 21:01:38.000000000 +0000
+++ ui/webui/resources/tools/minify_js.py
@@ -36,6 +36,7 @@ def main(argv):
   # launching NodeJS once for every input file.
   node.RunNode(
     [
+      '--jitless',
       os.path.join(_HERE_PATH, 'minify_js.js'),
       '--in_folder',
       in_path,
