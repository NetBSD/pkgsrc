$NetBSD: patch-lib_action__text.rb,v 1.1 2023/11/30 15:37:16 taca Exp $

* Fix rdoc error.

--- lib/action_text.rb.orig	2023-10-08 15:24:38.882061246 +0000
+++ lib/action_text.rb
@@ -9,7 +9,7 @@ require "action_text/deprecator"
 require "nokogiri"
 
 # :markup: markdown
-# :include: actiontext/README.md
+# :include: ../README.md
 module ActionText
   extend ActiveSupport::Autoload
 
