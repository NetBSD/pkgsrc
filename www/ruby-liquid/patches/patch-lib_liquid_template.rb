$NetBSD: patch-lib_liquid_template.rb,v 1.1 2024/01/21 09:07:55 taca Exp $

Remove support for taint checking.

--- lib/liquid/template.rb.orig	2024-01-15 06:05:42.706300643 +0000
+++ lib/liquid/template.rb
@@ -63,12 +63,6 @@ module Liquid
       # :strict will enforce correct syntax.
       attr_writer :error_mode
 
-      # Sets how strict the taint checker should be.
-      # :lax is the default, and ignores the taint flag completely
-      # :warn adds a warning, but does not interrupt the rendering
-      # :error raises an error when tainted output is used
-      attr_writer :taint_mode
-
       attr_accessor :default_exception_renderer
       Template.default_exception_renderer = lambda do |exception|
         exception
@@ -94,10 +88,6 @@ module Liquid
         @error_mode ||= :lax
       end
 
-      def taint_mode
-        @taint_mode ||= :lax
-      end
-
       # Pass a module with filter methods which should be available
       # to all liquid views. Good for registering the standard library
       def register_filter(mod)
