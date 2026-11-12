$NetBSD: patch-lib_neocities_client.rb,v 1.2 2026/11/12 15:12:35 ktnb Exp $

* Fix errors from delete command.

--- lib/neocities/client.rb.orig	2026-11-12 14:13:20.568398944 +0000
+++ lib/neocities/client.rb
@@ -147,8 +147,8 @@ module Neocities
       end
     end
 
-    def delete(*paths)
-      post 'delete', 'filenames[]' => paths
+    def delete(path)
+      post 'delete', 'filenames[]' => path
     end
 
     def info(sitename=nil)
