$NetBSD: patch-src_3rdparty_chromium_printing_cups__config__helper.py,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/printing/cups_config_helper.py.orig	2020-07-15 18:56:00.000000000 +0000
+++ src/3rdparty/chromium/printing/cups_config_helper.py
@@ -67,7 +67,7 @@ def main():
   mode = sys.argv[1]
   if len(sys.argv) > 2 and sys.argv[2]:
     sysroot = sys.argv[2]
-    cups_config = os.path.join(sysroot, 'usr', 'bin', 'cups-config')
+    cups_config = os.path.join(sysroot, 'bin', 'cups-config')
     if not os.path.exists(cups_config):
       print('cups-config not found: %s' % cups_config)
       return 1
