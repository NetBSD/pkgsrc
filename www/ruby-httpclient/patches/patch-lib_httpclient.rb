$NetBSD: patch-lib_httpclient.rb,v 1.1 2021/10/01 15:31:26 tsutsui Exp $

- workaround expired root certificates
 https://github.com/nahi/httpclient/pull/447

--- lib/httpclient.rb.orig	2021-10-01 01:47:06.607892120 +0000
+++ lib/httpclient.rb
@@ -450,6 +450,7 @@ class HTTPClient
     self.proxy = proxy if proxy
     keep_webmock_compat
     instance_eval(&block) if block
+    @session_manager&.ssl_config&.set_default_paths
   end
 
   # webmock 1.6.2 depends on HTTP::Message#body.content to work.
