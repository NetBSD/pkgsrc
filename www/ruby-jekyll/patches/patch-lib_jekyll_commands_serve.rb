$NetBSD: patch-lib_jekyll_commands_serve.rb,v 1.1.2.2 2022/10/27 06:28:12 bsiegert Exp $

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
