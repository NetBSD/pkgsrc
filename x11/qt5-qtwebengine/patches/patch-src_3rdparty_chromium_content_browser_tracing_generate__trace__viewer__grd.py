$NetBSD: patch-src_3rdparty_chromium_content_browser_tracing_generate__trace__viewer__grd.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/content/browser/tracing/generate_trace_viewer_grd.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/content/browser/tracing/generate_trace_viewer_grd.py
@@ -74,7 +74,7 @@ def main(argv):
   for filename in parsed_args.source_files:
     add_file_to_grd(doc, os.path.basename(filename))
 
-  with open(parsed_args.output_filename, 'w') as output_file:
+  with open(parsed_args.output_filename, 'wb') as output_file:
     output_file.write(doc.toxml(encoding='UTF-8'))
 
 
