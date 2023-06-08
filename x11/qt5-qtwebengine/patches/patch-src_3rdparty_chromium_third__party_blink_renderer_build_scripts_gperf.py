$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_build_scripts_gperf.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/build/scripts/gperf.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/build/scripts/gperf.py
@@ -95,7 +95,7 @@ def main():
 
     open(args.output_file, 'wb').write(
         generate_gperf(gperf_path,
-                       open(infile).read(), gperf_args))
+                       open(infile).read(), gperf_args).encode('utf-8'))
 
 
 if __name__ == '__main__':
