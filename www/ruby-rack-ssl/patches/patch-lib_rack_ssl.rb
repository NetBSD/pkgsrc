$NetBSD: patch-lib_rack_ssl.rb,v 1.1 2014/03/21 01:06:47 taca Exp $

Security fix for CVE-2014-2538.

--- lib/rack/ssl.rb.orig	2014-03-19 13:38:14.000000000 +0000
+++ lib/rack/ssl.rb
@@ -55,6 +55,8 @@ module Rack
                                         'Location'     => url.to_s)
 
         [status, headers, []]
+      rescue URI::InvalidURIError
+        [400, {"Content-Type" => "text/plain"}, []]
       end
 
       # http://tools.ietf.org/html/draft-hodges-strict-transport-sec-02
