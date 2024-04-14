$NetBSD: patch-Source_WebInspectorUI_Scripts_update-LegacyInspectorBackendCommands.rb,v 1.1 2024/04/14 12:44:52 tsutsui Exp $

- Apply upstream fixes for Ruby 3.2:
  https://bugs.webkit.org/show_bug.cgi?id=246743
  https://github.com/WebKit/WebKit/commit/b7ac5d0

--- Source/WebInspectorUI/Scripts/update-LegacyInspectorBackendCommands.rb.orig	2024-04-14 07:15:51.337488659 +0000
+++ Source/WebInspectorUI/Scripts/update-LegacyInspectorBackendCommands.rb
@@ -36,7 +36,7 @@ class Task
       end
 
       generated_path = File.join tmpdir, output_filename
-      if !File.exists?(generated_path)
+      if !File.exist?(generated_path)
         puts "ERROR: Generated file does not exist at expected path."
         exit 1
       end
