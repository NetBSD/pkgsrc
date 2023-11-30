$NetBSD: patch-lib_action__view.rb,v 1.1 2023/11/30 15:19:29 taca Exp $

* Fix rdoc error.

--- lib/action_view.rb.orig	2023-10-08 15:01:06.203624021 +0000
+++ lib/action_view.rb
@@ -28,7 +28,7 @@ require "active_support/rails"
 require "action_view/version"
 require "action_view/deprecator"
 
-# :include: actionview/README.rdoc
+# :include: ../README.rdoc
 module ActionView
   extend ActiveSupport::Autoload
 
