$NetBSD: patch-src_3rdparty_chromium_build_linux_strip__binary.py,v 1.1 2025/12/21 09:38:17 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/build/linux/strip_binary.py.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/build/linux/strip_binary.py
@@ -10,6 +10,7 @@ import sys
 
 
 def main():
+  return 0
   argparser = argparse.ArgumentParser(description='eu-strip binary.')
 
   argparser.add_argument('--eu-strip-binary-path', help='eu-strip path.')
