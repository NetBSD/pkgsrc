$NetBSD: patch-test_test__helper.rb,v 1.1 2024/01/21 09:07:55 taca Exp $

Remove support for taint checking.

--- test/test_helper.rb.orig	2024-01-15 06:05:42.719136612 +0000
+++ test/test_helper.rb
@@ -69,14 +69,6 @@ module Minitest
       Liquid::Strainer.class_variable_set(:@@global_strainer, original_global_strainer)
     end
 
-    def with_taint_mode(mode)
-      old_mode = Liquid::Template.taint_mode
-      Liquid::Template.taint_mode = mode
-      yield
-    ensure
-      Liquid::Template.taint_mode = old_mode
-    end
-
     def with_error_mode(mode)
       old_mode = Liquid::Template.error_mode
       Liquid::Template.error_mode = mode
