$NetBSD: patch-lib_jekyll_commands_new.rb,v 1.2 2018/03/13 17:49:49 taca Exp $

Do not use bundle unless specify --execute-bundle option.

--- lib/jekyll/commands/new.rb.orig	2017-10-15 15:52:10.000000000 +0000
+++ lib/jekyll/commands/new.rb
@@ -15,6 +15,8 @@ module Jekyll
             c.option "blank", "--blank", "Creates scaffolding but with empty files"
             c.option "skip-bundle", "--skip-bundle", "Skip 'bundle install'"
 
+            c.option "execute-bundle", "--execute-bundle", "Use 'bundle install'"
+
             c.action do |args, options|
               Jekyll::Commands::New.process(args, options)
             end
@@ -127,7 +129,8 @@ RUBY
         # unless the user opts to generate a blank blog or skip 'bundle install'.
 
         def after_install(path, options = {})
-          unless options["blank"] || options["skip-bundle"]
+          execute_bundle = options["execute-bundle"]
+          unless options["blank"] || options["skip-bundle"] || (not execute_bundle)
             begin
               require "bundler"
               bundle_install path
@@ -137,7 +140,7 @@ RUBY
           end
 
           Jekyll.logger.info "New jekyll site installed in #{path.cyan}."
-          Jekyll.logger.info "Bundle install skipped." if options["skip-bundle"]
+          Jekyll.logger.info "Bundle install skipped." if options["skip-bundle"] || (not execute_bundle)
         end
 
         def bundle_install(path)
