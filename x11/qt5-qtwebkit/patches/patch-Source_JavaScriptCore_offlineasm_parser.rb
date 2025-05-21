$NetBSD: patch-Source_JavaScriptCore_offlineasm_parser.rb,v 1.1 2025/05/21 16:47:21 taca Exp $

Make it work with Ruby 3.2 and later.

--- Source/JavaScriptCore/offlineasm/parser.rb.orig	2025-05-21 16:24:45.640169260 +0000
+++ Source/JavaScriptCore/offlineasm/parser.rb
@@ -584,7 +584,7 @@ class Parser
         firstCodeOrigin = @tokens[@idx].codeOrigin
         list = []
         loop {
-            if (@idx == @tokens.length and not final) or (final and @tokens[@idx] =~ final)
+            if (@idx == @tokens.length and not final) or (final and @tokens[@idx].is_a? Token and @tokens[@idx] =~ final)
                 break
             elsif @tokens[@idx].is_a? Annotation
                 # This is the only place where we can encounter a global
