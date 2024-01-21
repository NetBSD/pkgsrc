$NetBSD: patch-lib_liquid_variable.rb,v 1.1 2024/01/21 09:07:55 taca Exp $

Remove support for taint checking.

--- lib/liquid/variable.rb.orig	2024-01-15 06:05:42.707479051 +0000
+++ lib/liquid/variable.rb
@@ -84,11 +84,7 @@ module Liquid
         context.invoke(filter_name, output, *filter_args)
       end
 
-      obj = context.apply_global_filter(obj)
-
-      taint_check(context, obj)
-
-      obj
+      context.apply_global_filter(obj)
     end
 
     private
@@ -120,25 +116,6 @@ module Liquid
       parsed_args
     end
 
-    def taint_check(context, obj)
-      return unless obj.tainted?
-      return if Template.taint_mode == :lax
-
-      @markup =~ QuotedFragment
-      name = Regexp.last_match(0)
-
-      error = TaintedError.new("variable '#{name}' is tainted and was not escaped")
-      error.line_number = line_number
-      error.template_name = context.template_name
-
-      case Template.taint_mode
-      when :warn
-        context.warnings << error
-      when :error
-        raise error
-      end
-    end
-
     class ParseTreeVisitor < Liquid::ParseTreeVisitor
       def children
         [@node.name] + @node.filters.flatten
