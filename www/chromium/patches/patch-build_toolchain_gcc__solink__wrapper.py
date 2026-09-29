$NetBSD: patch-build_toolchain_gcc__solink__wrapper.py,v 1.27 2026/09/29 07:42:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- build/toolchain/gcc_solink_wrapper.py.orig	2026-09-22 00:09:16.000000000 +0000
+++ build/toolchain/gcc_solink_wrapper.py
@@ -41,7 +41,7 @@ def CollectDynSym(args):
     toc = ''
     nm = subprocess.Popen(
         wrapper_utils.CommandToRun(
-            [args.nm, '--format=posix', '-g', '-D', '-p', args.output]
+            [args.nm, '-g', '-D', '-p', args.output]
         ),
         stdout=subprocess.PIPE,
         bufsize=-1,
