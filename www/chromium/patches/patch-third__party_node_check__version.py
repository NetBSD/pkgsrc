$NetBSD: patch-third__party_node_check__version.py,v 1.12 2026/01/19 16:14:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/node/check_version.py.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/node/check_version.py
@@ -17,11 +17,6 @@ def main(argv):
   parser.add_argument('--out_file', required=True)
   args = parser.parse_args(argv)
 
-  node.RunNode([
-      os.path.join(_HERE_PATH, 'check_version.js'),
-      '--expected_version_file', args.expected_version_file,
-  ])
-
   # If the above script succeeded, write a dummy output file, since Ninja
   # requires every target to have an output.
   with open(args.out_file, "w") as file:
