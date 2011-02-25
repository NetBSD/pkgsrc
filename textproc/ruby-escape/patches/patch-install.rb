$NetBSD: patch-install.rb,v 1.1 2011/02/25 02:18:51 obache Exp $

staged installation support.

--- install.rb.orig	2007-01-03 18:24:56.000000000 +0000
+++ install.rb
@@ -102,6 +102,9 @@ if $opt_n
 else
   File.umask 022
   dir = target_directory
+  if (destdir = ENV['DESTDIR'])
+    dir = File.join(destdir, dir)
+  end
   collect_target.each {|filename|
     install_file filename, "#{dir}/#{filename}"
   }
