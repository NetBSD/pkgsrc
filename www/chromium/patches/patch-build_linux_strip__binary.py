$NetBSD: patch-build_linux_strip__binary.py,v 1.19 2026/05/10 15:29:48 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- build/linux/strip_binary.py.orig	2026-04-28 23:05:57.000000000 +0200
+++ build/linux/strip_binary.py
@@ -10,6 +10,7 @@ import sys
 
 
 def main() -> int:
+  return 0
   parser = argparse.ArgumentParser(description="Strip binary using LLVM tools.")
   parser.add_argument("--llvm-strip-binary-path",
                       help="Path to llvm-strip executable.")
