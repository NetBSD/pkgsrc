$NetBSD: patch-install.rb,v 1.1.1.1 2011/02/25 02:25:59 obache Exp $

* staged-installation support

--- install.rb.orig	2010-12-20 11:05:43.000000000 +0000
+++ install.rb
@@ -10,6 +10,10 @@ include Config
 SITELIBDIR = CONFIG["sitelibdir"]
 SRCPATH = File.join(File.dirname($0), 'lib')
 
+if (destdir = ENV['DESTDIR'])
+  SITELIBDIR = File.join(destdir, SITELIBDIR)
+end
+
 def install_file(from, to)
   unless File.directory?(to)
     to = File.dirname(to)
