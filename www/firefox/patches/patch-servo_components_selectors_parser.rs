$NetBSD: patch-servo_components_selectors_parser.rs,v 1.3 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/selectors/parser.rs.orig	2017-11-23 16:19:56.000000000 +0000
+++ servo/components/selectors/parser.rs
@@ -13,7 +13,6 @@ use precomputed_hash::PrecomputedHash;
 use servo_arc::ThinArc;
 use sink::Push;
 use smallvec::SmallVec;
-use std::ascii::AsciiExt;
 use std::borrow::{Borrow, Cow};
 use std::fmt::{self, Display, Debug, Write};
 use std::iter::Rev;
