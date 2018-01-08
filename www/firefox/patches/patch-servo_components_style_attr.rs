$NetBSD: patch-servo_components_style_attr.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/style/attr.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/style/attr.rs
@@ -16,7 +16,6 @@ use selectors::attr::AttrSelectorOperati
 use servo_arc::Arc;
 use servo_url::ServoUrl;
 use shared_lock::Locked;
-use std::ascii::AsciiExt;
 use std::str::FromStr;
 use str::{HTML_SPACE_CHARACTERS, read_exponent, read_fraction};
 use str::{read_numbers, split_commas, split_html_space_chars};
