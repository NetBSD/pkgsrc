$NetBSD: patch-rake_rakedocs.rb,v 1.1.1.1 2011/08/13 02:12:35 taca Exp $

* Some workaround related to load path.

--- rake/rakedocs.rb.orig	2009-09-08 20:36:50.000000000 +0000
+++ rake/rakedocs.rb
@@ -69,6 +69,7 @@ file 'doc/html/index.html' => [ 'doc/tex
   end
   puts "Rendering #{t.name}"
   src_file = File.join(DOC_TEXTILE_DIR, 'index.txtl')
+  $:.push "./lib"
   gen = IndexPageGenerator.new(src_file)
   gen.output(t.name)
 end
