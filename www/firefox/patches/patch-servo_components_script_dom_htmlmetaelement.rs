$NetBSD: patch-servo_components_script_dom_htmlmetaelement.rs,v 1.2.2.2 2018/03/09 07:17:30 spz Exp $

--- servo/components/script/dom/htmlmetaelement.rs.orig	2017-11-02 16:16:33.000000000 +0000
+++ servo/components/script/dom/htmlmetaelement.rs
@@ -22,7 +22,6 @@ use html5ever::{LocalName, Prefix};
 use parking_lot::RwLock;
 use servo_arc::Arc;
 use servo_config::prefs::PREFS;
-use std::ascii::AsciiExt;
 use std::sync::atomic::AtomicBool;
 use style::attr::AttrValue;
 use style::media_queries::MediaList;
