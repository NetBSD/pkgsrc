$NetBSD: patch-lib_jekyll_commands_new.rb,v 1.1 2017/04/22 17:13:48 taca Exp $

Do not use bundle unless specify --execute-bundle option.

--- lib/jekyll/commands/new.rb.orig	2017-04-22 08:36:18.000000000 +0000
+++ lib/jekyll/commands/new.rb
@@ -13,6 +13,8 @@ module Jekyll
             c.option "blank", "--blank", "Creates scaffolding but with empty files"
             c.option "skip-bundle", "--skip-bundle", "Skip 'bundle install'"
 
+            c.option "execute-bundle", "--execute-bundle", "Use 'bundle install'"
+
             c.action do |args, options|
               Jekyll::Commands::New.process(args, options)
             end
@@ -125,12 +127,13 @@ RUBY
         # unless the user opts to generate a blank blog or skip 'bundle install'.
 
         def after_install(path, options = {})
-          unless options["blank"] || options["skip-bundle"]
+          execute_bundle = options["execute-bundle"]
+          unless options["blank"] || options["skip-bundle"] || (not execute_bundle)
             bundle_install path
           end
 
           Jekyll.logger.info "New jekyll site installed in #{path.cyan}."
-          Jekyll.logger.info "Bundle install skipped." if options["skip-bundle"]
+          Jekyll.logger.info "Bundle install skipped." if options["skip-bundle"] or (not execute_bundle)
         end
 
         def bundle_install(path)
