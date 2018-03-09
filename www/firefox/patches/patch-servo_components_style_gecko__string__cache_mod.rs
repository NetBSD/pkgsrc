$NetBSD: patch-servo_components_style_gecko__string__cache_mod.rs,v 1.2.2.2 2018/03/09 07:17:30 spz Exp $

* Fix build with Rust 1.23.0

--- servo/components/style/gecko_string_cache/mod.rs.orig	2017-11-02 16:16:33.000000000 +0000
+++ servo/components/style/gecko_string_cache/mod.rs
@@ -13,7 +13,6 @@ use gecko_bindings::bindings::Gecko_Rele
 use gecko_bindings::structs::{nsIAtom, nsIAtom_AtomKind};
 use nsstring::{nsAString, nsString};
 use precomputed_hash::PrecomputedHash;
-use std::ascii::AsciiExt;
 use std::borrow::{Cow, Borrow};
 use std::char::{self, DecodeUtf16};
 use std::fmt::{self, Write};
