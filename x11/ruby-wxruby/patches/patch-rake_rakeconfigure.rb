$NetBSD: patch-rake_rakeconfigure.rb,v 1.1 2015/09/27 06:41:06 taca Exp $

--- rake/rakeconfigure.rb.orig	2009-09-08 20:36:50.000000000 +0000
+++ rake/rakeconfigure.rb
@@ -33,29 +33,29 @@ $excluded_classes = ENV['WXRUBY_EXCLUDED
 # Get ruby's info on how it was built
 require "rbconfig"
 
-$ruby_cppflags = Config::CONFIG["CFLAGS"]
+$ruby_cppflags = RbConfig::CONFIG["CFLAGS"]
 
 # Ruby 1.9.0 changes location of some header files
 if RUBY_VERSION >= "1.9.0"
-  includes = [ Config::CONFIG["rubyhdrdir"],
-               Config::CONFIG["sitehdrdir"],
-               Config::CONFIG["vendorhdrdir"],
-               File.join(Config::CONFIG["rubyhdrdir"], 
-                         Config::CONFIG['arch']) ]
+  includes = [ RbConfig::CONFIG["rubyhdrdir"],
+               RbConfig::CONFIG["sitehdrdir"],
+               RbConfig::CONFIG["vendorhdrdir"],
+               File.join(RbConfig::CONFIG["rubyhdrdir"], 
+                         RbConfig::CONFIG['arch']) ]
   $ruby_includes = " -I. -I " + includes.join(' -I ')
 else
-  $ruby_includes = " -I. -I " + Config::CONFIG["archdir"]
+  $ruby_includes = " -I. -I " + RbConfig::CONFIG["archdir"]
 end
 
-$ruby_ldflags = Config::CONFIG["LDFLAGS"]
-$ruby_libs  = Config::CONFIG["LIBS"]
+$ruby_ldflags = RbConfig::CONFIG["LDFLAGS"]
+$ruby_libs  = RbConfig::CONFIG["LIBS"]
 $extra_cppflags = ""
 $extra_ldflags = ""
 $extra_objs = ""
 $extra_libs = ""
 $cpp_out_flag =  "-o "
 $link_output_flag = "-o "
-OBJ_EXT = Config::CONFIG["OBJEXT"]
+OBJ_EXT = RbConfig::CONFIG["OBJEXT"]
 
 # This is now set with the detection of WXRUBY_EXCLUDED
 # some classes are not implemented by WxWidgets on all platforms
