$NetBSD: patch-rake_rakemingw.rb,v 1.1 2015/09/27 06:41:06 taca Exp $

--- rake/rakemingw.rb.orig	2009-09-08 20:36:50.000000000 +0000
+++ rake/rakemingw.rb
@@ -115,4 +115,4 @@ File.read(WXWIDGETS_SETUP_H).scan(/^#def
 end
 
 $extra_libs = "#{libs.join(' ')} " +
-  File.join(Config::CONFIG['libdir'], Config::CONFIG['LIBRUBY'])
+  File.join(RbConfig::CONFIG['libdir'], RbConfig::CONFIG['LIBRUBY'])
