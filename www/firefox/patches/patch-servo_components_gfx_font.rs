$NetBSD: patch-servo_components_gfx_font.rs,v 1.2.2.2 2018/03/09 07:17:30 spz Exp $

--- servo/components/gfx/font.rs.orig	2017-11-02 16:16:32.000000000 +0000
+++ servo/components/gfx/font.rs
@@ -10,7 +10,6 @@ use platform::font::{FontHandle, FontTab
 use platform::font_context::FontContextHandle;
 use platform::font_template::FontTemplateData;
 use smallvec::SmallVec;
-use std::ascii::AsciiExt;
 use std::borrow::ToOwned;
 use std::cell::RefCell;
 use std::collections::HashMap;
