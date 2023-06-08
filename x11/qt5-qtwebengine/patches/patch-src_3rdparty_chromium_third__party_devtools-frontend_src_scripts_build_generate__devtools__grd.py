$NetBSD: patch-src_3rdparty_chromium_third__party_devtools-frontend_src_scripts_build_generate__devtools__grd.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/devtools-frontend/src/scripts/build/generate_devtools_grd.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/devtools-frontend/src/scripts/build/generate_devtools_grd.py
@@ -123,7 +123,7 @@ def main(argv):
 
     try:
         os.makedirs(path.join(output_directory, 'Images'))
-    except OSError, e:
+    except OSError as e:
         if e.errno != errno.EEXIST:
             raise e
 
@@ -147,7 +147,7 @@ def main(argv):
             shutil.copy(path.join(dirname, filename), path.join(output_directory, 'Images'))
             add_file_to_grd(doc, path.join('Images', filename))
 
-    with open(parsed_args.output_filename, 'w') as output_file:
+    with open(parsed_args.output_filename, 'wb') as output_file:
         output_file.write(doc.toxml(encoding='UTF-8'))
 
 
