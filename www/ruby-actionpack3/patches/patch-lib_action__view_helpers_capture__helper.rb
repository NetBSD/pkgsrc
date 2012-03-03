$NetBSD: patch-lib_action__view_helpers_capture__helper.rb,v 1.1 2012/03/03 04:47:14 taca Exp $

Fix for CVE-2012-1099.

--- lib/action_view/helpers/capture_helper.rb.orig	2012-03-03 04:21:54.000000000 +0000
+++ lib/action_view/helpers/capture_helper.rb
@@ -179,7 +179,7 @@ module ActionView
       def flush_output_buffer #:nodoc:
         if output_buffer && !output_buffer.empty?
           response.body_parts << output_buffer
-          self.output_buffer = output_buffer[0,0]
+          self.output_buffer = output_buffer.respond_to?(:clone_empty) ? output_buffer.clone_empty : output_buffer[0, 0]
           nil
         end
       end
