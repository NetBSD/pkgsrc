$NetBSD: patch-lib_padrino-contrib_helpers_breadcrumbs.rb,v 1.1 2021/12/28 14:39:55 taca Exp $

Fix for CVE-2019-16145 from upstream commit:
662616162265a74da5a35b55c10f85d8168fc635.

--- lib/padrino-contrib/helpers/breadcrumbs.rb.orig	2021-12-28 14:30:14.586323532 +0000
+++ lib/padrino-contrib/helpers/breadcrumbs.rb
@@ -37,7 +37,7 @@ module Padrino
         def set_home(url, caption, options = {})
           self.home = {
             :url     => url.to_s,
-            :caption => caption.to_s.humanize.html_safe,
+            :caption => caption.to_s.humanize,
             :name    => :home,
             :options => options
           }
@@ -96,7 +96,7 @@ module Padrino
           items << {
             :name    => name.to_sym,
             :url     => url.to_s,
-            :caption => caption.to_s.humanize.html_safe,
+            :caption => caption.to_s.humanize,
             :options => options
           }
         end
