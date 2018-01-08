$NetBSD: patch-servo_components_script_dom_xmlhttprequest.rs,v 1.3 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/script/dom/xmlhttprequest.rs.orig	2017-11-02 16:16:33.000000000 +0000
+++ servo/components/script/dom/xmlhttprequest.rs
@@ -62,7 +62,6 @@ use script_traits::DocumentActivity;
 use servo_atoms::Atom;
 use servo_config::prefs::PREFS;
 use servo_url::ServoUrl;
-use std::ascii::AsciiExt;
 use std::borrow::ToOwned;
 use std::cell::Cell;
 use std::default::Default;
