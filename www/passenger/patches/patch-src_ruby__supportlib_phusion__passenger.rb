$NetBSD: patch-src_ruby__supportlib_phusion__passenger.rb,v 1.1 2018/01/30 12:06:48 fhajny Exp $

Default paths.

--- src/ruby_supportlib/phusion_passenger.rb.orig	2013-10-27 00:00:00.000000000 +0000
+++ src/ruby_supportlib/phusion_passenger.rb
@@ -57,8 +57,7 @@ module PhusionPassenger
 
   # Directories in which to look for plugins.
   PLUGIN_DIRS = [
-    "/usr/share/#{GLOBAL_NAMESPACE_DIRNAME_}/plugins",
-    "/usr/local/share/#{GLOBAL_NAMESPACE_DIRNAME_}/plugins",
+    "@PREFIX@/share/#{GLOBAL_NAMESPACE_DIRNAME_}/plugins",
     "~/#{USER_NAMESPACE_DIRNAME_}/plugins"
   ]
 
@@ -275,7 +274,7 @@ private
       return filename if File.exist?(filename)
     end
 
-    filename = "/etc/#{GLOBAL_NAMESPACE_DIRNAME_}/locations.ini"
+    filename = "@PKG_SYSCONFDIR@/locations.ini"
     return filename if File.exist?(filename)
 
     return nil
