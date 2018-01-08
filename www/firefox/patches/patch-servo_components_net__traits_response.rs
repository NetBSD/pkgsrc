$NetBSD: patch-servo_components_net__traits_response.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/net_traits/response.rs.orig	2017-11-02 16:16:32.000000000 +0000
+++ servo/components/net_traits/response.rs
@@ -9,7 +9,6 @@ use hyper::header::{AccessControlExposeH
 use hyper::status::StatusCode;
 use hyper_serde::Serde;
 use servo_url::ServoUrl;
-use std::ascii::AsciiExt;
 use std::sync::{Arc, Mutex};
 
 /// [Response type](https://fetch.spec.whatwg.org/#concept-response-type)
