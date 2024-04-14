$NetBSD: patch-Source_JavaScriptCore_offlineasm_parser.rb,v 1.1 2024/04/14 12:44:52 tsutsui Exp $

- Apply upstream fixes for Ruby 3.2:
  https://bugs.webkit.org/show_bug.cgi?id=246743
  https://github.com/WebKit/WebKit/commit/b7ac5d0

--- Source/JavaScriptCore/offlineasm/parser.rb.orig	2024-04-14 07:15:12.925145845 +0000
+++ Source/JavaScriptCore/offlineasm/parser.rb
@@ -838,10 +838,10 @@ class Parser
                     additionsDirectoryName = "#{@buildProductsDirectory}/usr/local/include/WebKitAdditions/"
                 end
                 fileName = IncludeFile.new(moduleName, additionsDirectoryName).fileName
-                if not File.exists?(fileName)
+                if not File.exist?(fileName)
                     fileName = IncludeFile.new(moduleName, @tokens[@idx].codeOrigin.fileName.dirname).fileName
                 end
-                fileExists = File.exists?(fileName)
+                fileExists = File.exist?(fileName)
                 raise "File not found: #{fileName}" if not fileExists and not isOptional
                 list << parse(fileName, @options) if fileExists
             else
@@ -874,10 +874,10 @@ class Parser
                     additionsDirectoryName = "#{@buildProductsDirectory}/usr/local/include/WebKitAdditions/"
                 end
                 fileName = IncludeFile.new(moduleName, additionsDirectoryName).fileName
-                if not File.exists?(fileName)
+                if not File.exist?(fileName)
                     fileName = IncludeFile.new(moduleName, @tokens[@idx].codeOrigin.fileName.dirname).fileName
                 end
-                fileExists = File.exists?(fileName)
+                fileExists = File.exist?(fileName)
                 raise "File not found: #{fileName}" if not fileExists and not isOptional
                 fileList << fileName if fileExists
             else
