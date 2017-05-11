$NetBSD: patch-ext_gtk2_extconf.rb,v 1.1 2017/05/11 09:08:14 jperkin Exp $

Use INCFLAGS to find includes.

--- ext/gtk2/extconf.rb.orig	2017-05-11 08:54:39.678533544 +0000
+++ ext/gtk2/extconf.rb
@@ -68,7 +68,7 @@ $defs << "-DRUBY_GTK2_TARGET=\\\"#{targe
 STDOUT.print(target, "\n")
 
 gdk_include_path = nil
-include_paths = $CFLAGS.gsub(/-D\w+/, '').split(/-I/) + ['/usr/include']
+include_paths = $INCFLAGS.gsub(/-D\w+/, '').split(/-I/) + ['/usr/include']
 include_paths.each do |path|
   path.strip!
 
