$NetBSD: patch-build_linux_strip__binary.py,v 1.33 2026/11/19 19:45:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- build/linux/strip_binary.py.orig	2026-11-11 21:01:38.000000000 +0000
+++ build/linux/strip_binary.py
@@ -10,6 +10,7 @@ import sys
 
 
 def main() -> int:
+    return 0
     parser = argparse.ArgumentParser(
         description="Strip binary using LLVM tools."
     )
