$NetBSD: patch-lib_jekyll_commands_serve.rb,v 1.1 2022/10/16 04:17:23 taca Exp $

* "jekyll serve" require webrick.

--- lib/jekyll/commands/serve.rb.orig	2022-10-16 04:11:09.565369814 +0000
+++ lib/jekyll/commands/serve.rb
@@ -1,5 +1,7 @@
 # frozen_string_literal: true
 
+require 'webrick'
+
 module Jekyll
   module Commands
     class Serve < Command
