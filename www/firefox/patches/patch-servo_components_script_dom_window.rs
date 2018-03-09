$NetBSD: patch-servo_components_script_dom_window.rs,v 1.2.2.2 2018/03/09 07:17:30 spz Exp $

--- servo/components/script/dom/window.rs.orig	2017-11-02 16:16:33.000000000 +0000
+++ servo/components/script/dom/window.rs
@@ -87,7 +87,6 @@ use servo_config::opts;
 use servo_config::prefs::PREFS;
 use servo_geometry::{f32_rect_to_au_rect, max_rect};
 use servo_url::{Host, MutableOrigin, ImmutableOrigin, ServoUrl};
-use std::ascii::AsciiExt;
 use std::borrow::ToOwned;
 use std::cell::Cell;
 use std::collections::{HashMap, HashSet};
