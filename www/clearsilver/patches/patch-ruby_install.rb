$NetBSD: patch-ruby_install.rb,v 1.1 2015/06/11 16:43:32 taca Exp $

Fix build problem on Ruby 2.2 and later.

--- ruby/install.rb.orig	2005-06-30 18:51:57.000000000 +0000
+++ ruby/install.rb
@@ -45,7 +45,7 @@ end
 
 class ConfigTable
 
-  c = ::Config::CONFIG
+  c = ::RbConfig::CONFIG
 
   rubypath = c['bindir'] + '/' + c['ruby_install_name']
 
@@ -695,7 +695,7 @@ class Installer
         "no extention exists: Have you done 'ruby #{$0} setup' ?"
   end
 
-  DLEXT = /\.#{ ::Config::CONFIG['DLEXT'] }\z/
+  DLEXT = /\.#{ ::RbConfig::CONFIG['DLEXT'] }\z/
 
   def _allext( dir )
     Dir.open( dir ) {|d|
