$NetBSD: patch-lib_termtter_command.rb,v 1.1 2011/04/02 14:47:00 taca Exp $

Fix for starnge rdoc crash.

--- lib/termtter/command.rb.orig	2011-03-31 05:19:12.000000000 +0000
+++ lib/termtter/command.rb
@@ -84,7 +84,7 @@ module Termtter
       /^\s*((#{commands_regex})|(#{commands_regex})\s+(.*?))\s*$/
     end
 
-    # commands :: [Symbol]
+    # commands :: # [Symbol]
     def commands
       [name] + aliases
     end
