$NetBSD: patch-src_3rdparty_chromium_build_toolchain_gcc__solink__wrapper.py,v 1.1 2025/12/21 09:38:18 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/build/toolchain/gcc_solink_wrapper.py.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/build/toolchain/gcc_solink_wrapper.py
@@ -39,7 +39,7 @@ def CollectDynSym(args):
   """Replaces: nm --format=posix -g -D -p $sofile | cut -f1-2 -d' '"""
   toc = ''
   nm = subprocess.Popen(wrapper_utils.CommandToRun(
-      [args.nm, '--format=posix', '-g', '-D', '-p', args.sofile]),
+      [args.nm, '-g', '-D', '-p', args.sofile]),
                         stdout=subprocess.PIPE,
                         bufsize=-1,
                         universal_newlines=True)
