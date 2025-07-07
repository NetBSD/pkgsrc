$NetBSD: patch-build_toolchain_gcc__solink__wrapper.py,v 1.3 2025/07/07 09:23:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- build/toolchain/gcc_solink_wrapper.py.orig	2025-06-30 06:54:11.000000000 +0000
+++ build/toolchain/gcc_solink_wrapper.py
@@ -39,7 +39,7 @@ def CollectDynSym(args):
   """Replaces: nm --format=posix -g -D -p $sofile | cut -f1-2 -d' '"""
   toc = ''
   nm = subprocess.Popen(wrapper_utils.CommandToRun(
-      [args.nm, '--format=posix', '-g', '-D', '-p', args.sofile]),
+      [args.nm, '-g', '-D', '-p', args.sofile]),
                         stdout=subprocess.PIPE,
                         bufsize=-1,
                         universal_newlines=True)
