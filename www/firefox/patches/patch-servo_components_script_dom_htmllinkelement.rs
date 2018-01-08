$NetBSD: patch-servo_components_script_dom_htmllinkelement.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/script/dom/htmllinkelement.rs.orig	2017-11-02 16:16:33.000000000 +0000
+++ servo/components/script/dom/htmllinkelement.rs
@@ -26,7 +26,6 @@ use html5ever::{LocalName, Prefix};
 use net_traits::ReferrerPolicy;
 use script_traits::{MozBrowserEvent, ScriptMsg};
 use servo_arc::Arc;
-use std::ascii::AsciiExt;
 use std::borrow::ToOwned;
 use std::cell::Cell;
 use std::default::Default;
