$NetBSD: patch-setup.rb,v 1.1 2015/06/11 16:44:34 taca Exp $

Fix build problem on Ruby 2.2 and later.

--- setup.rb.orig	2003-12-20 23:35:39.000000000 +0000
+++ setup.rb
@@ -218,7 +218,7 @@ end
 
 class ConfigTable
 
-  c = ::Config::CONFIG
+  c = ::RbConfig::CONFIG
 
   rubypath = c['bindir'] + '/' + c['ruby_install_name']
 
@@ -796,7 +796,7 @@ class Installer
         raise InstallError, "no ruby extention exists: 'ruby #{$0} setup' first"
   end
 
-  DLEXT = /\.#{ ::Config::CONFIG['DLEXT'] }\z/
+  DLEXT = /\.#{ ::RbConfig::CONFIG['DLEXT'] }\z/
 
   def _ruby_extentions(dir)
     Dir.open(dir) {|d|
