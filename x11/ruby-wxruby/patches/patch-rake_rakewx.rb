$NetBSD: patch-rake_rakewx.rb,v 1.1.1.1 2011/08/13 02:12:35 taca Exp $

* Tweak to use vendorlibdir/vendorarchdir instead of sitelbdir/sitearchdir.

--- rake/rakewx.rb.orig	2009-09-08 20:36:50.000000000 +0000
+++ rake/rakewx.rb
@@ -162,10 +162,16 @@ end
 
 desc "Install the WxRuby library to Ruby's lib directories"
 task :install => [ :default, *ALL_RUBY_LIB_FILES ] do | t |
-  dest_dir = Config::CONFIG['sitelibdir']
+  if ENV['DESTDIR'].nil?
+    arch_dir = Config::CONFIG['vendorarchdir']
+    dest_dir = Config::CONFIG['vendorlibdir']
+  else
+    arch_dir = File.join(ENV['DESTDIR'], Config::CONFIG['vendorarchdir'])
+    dest_dir = File.join(ENV['DESTDIR'], Config::CONFIG['vendorlibdir'])
+  end
   force_mkdir File.join(dest_dir, 'wx')
   force_mkdir File.join(dest_dir, 'wx', 'classes')
-  cp TARGET_LIB, Config::CONFIG['sitearchdir']
+  cp TARGET_LIB, arch_dir
   ALL_RUBY_LIB_FILES.each do | lib_file |
     dest = lib_file.sub(/^lib/, dest_dir)
     cp lib_file, dest
@@ -175,9 +181,9 @@ end
 
 desc "Removes installed library files from site_ruby"
 task :uninstall do | t |
-  rm_rf File.join(Config::CONFIG['sitearchdir'],File.basename(TARGET_LIB))
-  rm_rf File.join(Config::CONFIG['sitelibdir'], 'wx.rb')
-  rm_rf File.join(Config::CONFIG['sitelibdir'], 'wx')
+  rm_rf File.join(Config::CONFIG['vendorarchdir'],File.basename(TARGET_LIB))
+  rm_rf File.join(Config::CONFIG['vendorlibdir'], 'wx.rb')
+  rm_rf File.join(Config::CONFIG['vendorlibdir'], 'wx')
 end
 
 desc "Generate C++ source and header files using SWIG"
