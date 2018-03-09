$NetBSD: patch-servo_components_net_fetch_methods.rs,v 1.2.2.2 2018/03/09 07:17:30 spz Exp $

--- servo/components/net/fetch/methods.rs.orig	2017-11-02 16:16:32.000000000 +0000
+++ servo/components/net/fetch/methods.rs
@@ -21,7 +21,6 @@ use net_traits::request::{CredentialsMod
 use net_traits::request::{Type, Origin, Window};
 use net_traits::response::{Response, ResponseBody, ResponseType};
 use servo_url::ServoUrl;
-use std::ascii::AsciiExt;
 use std::borrow::Cow;
 use std::fmt;
 use std::fs::File;
