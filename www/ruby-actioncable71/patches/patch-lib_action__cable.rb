$NetBSD: patch-lib_action__cable.rb,v 1.1 2023/11/30 15:32:42 taca Exp $

* Fix rdoc error.

--- lib/action_cable.rb.orig	2023-10-08 15:18:14.529632160 +0000
+++ lib/action_cable.rb
@@ -44,7 +44,7 @@ Zeitwerk::Loader.for_gem.tap do |loader|
 end.setup
 
 # :markup: markdown
-# :include: actioncable/README.md
+# :include: ../README.md
 module ActionCable
   require_relative "action_cable/version"
   require_relative "action_cable/deprecator"
