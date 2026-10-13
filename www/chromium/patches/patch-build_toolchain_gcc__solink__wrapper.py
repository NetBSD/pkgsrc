$NetBSD: patch-build_toolchain_gcc__solink__wrapper.py,v 1.29 2026/10/13 13:16:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- build/toolchain/gcc_solink_wrapper.py.orig	2026-10-06 00:06:58.000000000 +0000
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
