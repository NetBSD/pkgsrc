$NetBSD: patch-lib_jekyll_commands_new.rb,v 1.3 2021/12/12 13:40:34 taca Exp $

Do not use bundle unless specify --execute-bundle option.

--- lib/jekyll/commands/new.rb.orig	2021-10-25 13:37:13.511954374 +0000
+++ lib/jekyll/commands/new.rb
@@ -14,6 +14,7 @@ module Jekyll
             c.option "force", "--force", "Force creation even if PATH already exists"
             c.option "blank", "--blank", "Creates scaffolding but with empty files"
             c.option "skip-bundle", "--skip-bundle", "Skip 'bundle install'"
+            c.option "execute-bundle", "--execute-bundle", "Use 'bundle install'"
 
             c.action do |args, options|
               Jekyll::Commands::New.process(args, options)
@@ -137,7 +138,8 @@ module Jekyll
         # unless the user opts to generate a blank blog or skip 'bundle install'.
 
         def after_install(path, options = {})
-          unless options["blank"] || options["skip-bundle"]
+          execute_bundle = options["execute-bundle"]
+          unless options["blank"] || options["skip-bundle"] || (not execute_bundle)
             begin
               require "bundler"
               bundle_install path
@@ -147,7 +149,7 @@ module Jekyll
           end
 
           Jekyll.logger.info "New jekyll site installed in #{path.cyan}."
-          Jekyll.logger.info "Bundle install skipped." if options["skip-bundle"]
+          Jekyll.logger.info "Bundle install skipped." if options["skip-bundle"] || (not execute_bundle)
         end
 
         def bundle_install(path)
