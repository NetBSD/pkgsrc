$NetBSD: patch-servo_components_script_dom_document.rs,v 1.3 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/script/dom/document.rs.orig	2017-11-02 16:16:33.000000000 +0000
+++ servo/components/script/dom/document.rs
@@ -123,7 +123,6 @@ use servo_arc::Arc;
 use servo_atoms::Atom;
 use servo_config::prefs::PREFS;
 use servo_url::{ImmutableOrigin, MutableOrigin, ServoUrl};
-use std::ascii::AsciiExt;
 use std::borrow::ToOwned;
 use std::cell::{Cell, Ref, RefMut};
 use std::collections::{HashMap, HashSet, VecDeque};
