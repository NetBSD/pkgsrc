$NetBSD: patch-lib_neocities_client.rb,v 1.1 2026/07/23 15:15:18 ryoon Exp $

* Fix errors from delete command.

--- lib/neocities/client.rb.orig	2026-06-13 18:43:16.633986300 +0000
+++ lib/neocities/client.rb
@@ -147,8 +147,8 @@ module Neocities
       end
     end
 
-    def delete(*paths)
-      post 'delete', 'filenames[]' => paths
+    def delete(path)
+      post 'delete', 'filenames[]' => path
     end
 
     def info(sitename)
@@ -168,4 +168,4 @@ module Neocities
       JSON.parse resp.body, symbolize_names: true
     end
   end
-end
\ No newline at end of file
+end
