$NetBSD: patch-build_toolchain_gcc__solink__wrapper.py,v 1.24 2026/08/09 06:31:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- build/toolchain/gcc_solink_wrapper.py.orig	2026-08-05 20:17:42.000000000 +0000
+++ build/toolchain/gcc_solink_wrapper.py
@@ -39,7 +39,7 @@ def CollectDynSym(args):
   """Replaces: nm --format=posix -g -D -p $sofile | cut -f1-2 -d' '"""
   toc = ''
   nm = subprocess.Popen(wrapper_utils.CommandToRun(
-      [args.nm, '--format=posix', '-g', '-D', '-p', args.output]),
+      [args.nm, '-g', '-D', '-p', args.output]),
                         stdout=subprocess.PIPE,
                         bufsize=-1,
                         universal_newlines=True)
