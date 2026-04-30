$NetBSD: patch-src_3rdparty_chromium_build_linux_strip__binary.py,v 1.2 2026/04/30 06:39:35 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/build/linux/strip_binary.py.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/build/linux/strip_binary.py
@@ -10,6 +10,7 @@ import sys
 
 
 def main() -> int:
+  return 0
   parser = argparse.ArgumentParser(description="Strip binary using LLVM tools.")
   parser.add_argument("--llvm-strip-binary-path",
                       help="Path to llvm-strip executable.")
