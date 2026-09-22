$NetBSD: patch-build_linux_strip__binary.py,v 1.26 2026/09/22 13:41:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- build/linux/strip_binary.py.orig	2026-09-14 22:17:16.000000000 +0000
+++ build/linux/strip_binary.py
@@ -10,6 +10,7 @@ import sys
 
 
 def main() -> int:
+    return 0
     parser = argparse.ArgumentParser(
         description="Strip binary using LLVM tools."
     )
