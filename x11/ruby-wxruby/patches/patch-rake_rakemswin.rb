$NetBSD: patch-rake_rakemswin.rb,v 1.1 2015/09/27 06:41:06 taca Exp $

--- rake/rakemswin.rb.orig	2009-09-08 20:36:50.000000000 +0000
+++ rake/rakemswin.rb
@@ -97,7 +97,7 @@ if $unicode_build
 end
 
 # Extra files for the linker - WINDOWS_SYS_LIBS are common in rakewindows.rb
-lib_ruby =   File.join(Config::CONFIG['libdir'], Config::CONFIG['LIBRUBY'])
+lib_ruby =   File.join(RbConfig::CONFIG['libdir'], RbConfig::CONFIG['LIBRUBY'])
 $extra_libs = WINDOWS_SYS_LIBS.map { | lib | "#{lib}.lib" }.join(" ")
 $extra_libs << " #{lib_ruby}"
 
@@ -128,14 +128,14 @@ file 'temp' do
 # This is a temporary rakefile to install the Microsoft v8 runtime
 require 'rbconfig'
 task :default do
-  mv 'msvcp80.dll', Config::CONFIG['bindir']
-  mv 'msvcr80.dll', Config::CONFIG['bindir']
-  ruby_manifest = File.join(Config::CONFIG['bindir'], 'ruby.exe.manifest')
+  mv 'msvcp80.dll', RbConfig::CONFIG['bindir']
+  mv 'msvcr80.dll', RbConfig::CONFIG['bindir']
+  ruby_manifest = File.join(RbConfig::CONFIG['bindir'], 'ruby.exe.manifest')
   if File.exists? ruby_manifest 
     mv ruby_manifest, ruby_manifest + ".old"
   end
   cp 'wxruby2.so.manifest', ruby_manifest
-  rubyw_manifest = File.join(Config::CONFIG['bindir'], 'rubyw.exe.manifest')
+  rubyw_manifest = File.join(RbConfig::CONFIG['bindir'], 'rubyw.exe.manifest')
   if File.exists? rubyw_manifest 
     mv rubyw_manifest, rubyw_manifest + ".old"
   end
