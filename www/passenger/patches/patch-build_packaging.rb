$NetBSD: patch-build_packaging.rb,v 1.1 2018/01/30 12:06:48 fhajny Exp $

Mangle faceroot support for our purposes.
Improve portability (xargs).

--- build/packaging.rb.orig	2013-10-27 00:00:00.000000000 +0000
+++ build/packaging.rb
@@ -115,7 +115,7 @@ def change_shebang(filename, value)
 end
 
 desc "Create a fakeroot, useful for building native packages"
-task :fakeroot => [:apache2, :nginx, 'nginx:as_dynamic_module', :doc] do
+task :fakeroot => [] do
   require 'rbconfig'
   include RbConfig
 
@@ -146,7 +146,7 @@ task :fakeroot => [:apache2, :nginx, 'ng
   psg_ruby       = ENV['RUBY'] || "#{fs_bindir}/ruby"
   psg_free_ruby  = ENV['FREE_RUBY'] || "/usr/bin/env ruby"
 
-  fakeroot = "#{PKG_DIR}/fakeroot"
+  fakeroot = ENV['DESTDIR'].nil? ? '' : ENV['DESTDIR']
   fake_rubylibdir = "#{fakeroot}#{psg_rubylibdir}"
   fake_nodelibdir = "#{fakeroot}#{psg_nodelibdir}"
   fake_libdir     = "#{fakeroot}#{psg_libdir}"
@@ -164,9 +164,6 @@ task :fakeroot => [:apache2, :nginx, 'ng
 
   packaging_method = ENV['NATIVE_PACKAGING_METHOD'] || ENV['PACKAGING_METHOD'] || "deb"
 
-  sh "rm -rf #{fakeroot}"
-  sh "mkdir -p #{fakeroot}"
-
   # Ruby sources
   sh "mkdir -p #{fake_rubylibdir}"
   sh "cp #{PhusionPassenger.ruby_libdir}/phusion_passenger.rb #{fake_rubylibdir}/"
@@ -261,10 +258,6 @@ task :fakeroot => [:apache2, :nginx, 'ng
     change_shebang("#{fake_sbindir}/#{exe}", shebang)
   end
 
-  # Apache 2 module
-  sh "mkdir -p #{File.dirname(fake_apache2_module_path)}"
-  sh "cp #{APACHE2_TARGET} #{fake_apache2_module_path}"
-
   # Ruby extension sources
   sh "mkdir -p #{fake_ruby_extension_source_dir}"
   sh "cp -R #{PhusionPassenger.ruby_extension_source_dir}/* #{fake_ruby_extension_source_dir}"
@@ -295,5 +288,5 @@ task :fakeroot => [:apache2, :nginx, 'ng
     end
   end
 
-  sh "find #{fakeroot} -name .DS_Store -print0 | xargs -0 rm -f"
+  sh "find #{fakeroot} -name .DS_Store -exec rm -f '{}' \\\;"
 end
