$NetBSD: patch-servo_components_net_fetch_cors__cache.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/net/fetch/cors_cache.rs.orig	2017-07-31 16:20:53.000000000 +0000
+++ servo/components/net/fetch/cors_cache.rs
@@ -12,7 +12,6 @@
 use hyper::method::Method;
 use net_traits::request::{CredentialsMode, Origin, Request};
 use servo_url::ServoUrl;
-use std::ascii::AsciiExt;
 use time::{self, Timespec};
 
 /// Union type for CORS cache entries
