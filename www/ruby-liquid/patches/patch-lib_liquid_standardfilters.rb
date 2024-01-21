$NetBSD: patch-lib_liquid_standardfilters.rb,v 1.1 2024/01/21 09:07:55 taca Exp $

Remove support for taint checking.

--- lib/liquid/standardfilters.rb.orig	2024-01-15 06:05:42.700069674 +0000
+++ lib/liquid/standardfilters.rb
@@ -39,7 +39,7 @@ module Liquid
     end
 
     def escape(input)
-      CGI.escapeHTML(input.to_s).untaint unless input.nil?
+      CGI.escapeHTML(input.to_s) unless input.nil?
     end
     alias_method :h, :escape
 
