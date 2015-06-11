$NetBSD: patch-install.rb,v 1.1 2015/06/11 17:10:46 taca Exp $

Fix build problem on Ruby 2.2 and later.

--- install.rb.orig	2003-01-21 11:50:39.000000000 +0000
+++ install.rb
@@ -45,7 +45,7 @@ end
 
 class ConfigTable
 
-  c = ::Config::CONFIG
+  c = ::RbConfig::CONFIG
 
   rubypath = c['bindir'] + '/' + c['ruby_install_name']
 
@@ -691,7 +691,7 @@ class Installer
         "no extention exists: Have you done 'ruby #{$0} setup' ?"
   end
 
-  DLEXT = /\.#{ ::Config::CONFIG['DLEXT'] }\z/
+  DLEXT = /\.#{ ::RbConfig::CONFIG['DLEXT'] }\z/
 
   def _allext( dir )
     Dir.open(dir) {|d|
