$NetBSD: patch-rake_rakenetbsd.rb,v 1.1.1.1 2011/08/13 02:12:35 taca Exp $

* Configuration for NetBSD.

--- rake/rakenetbsd.rb.orig	2009-09-08 20:36:50.000000000 +0000
+++ rake/rakenetbsd.rb
@@ -6,6 +6,20 @@
 #############################
 # platform-dependent settings
 
-use_wx_config
+require './rake/rakeunixish'
 
-$extra_ld_flags = '-shared'
+# pkgsrc include dir
+$wx_libs     = wx_config("--libs std,stc,gl")
+$extra_cppflags = "-I@PREFIX@include"
+
+# This class is not available on WXGTK
+$excluded_classes << 'PrinterDC'
+
+if false
+  p $wx_version
+  p $wx_cppflags
+  p $cpp
+  p $ld
+  p $wx_libs
+  exit
+end
