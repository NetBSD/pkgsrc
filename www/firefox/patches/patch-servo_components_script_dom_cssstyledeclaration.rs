$NetBSD: patch-servo_components_script_dom_cssstyledeclaration.rs,v 1.3 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/script/dom/cssstyledeclaration.rs.orig	2017-11-02 16:16:33.000000000 +0000
+++ servo/components/script/dom/cssstyledeclaration.rs
@@ -16,7 +16,6 @@ use dom::window::Window;
 use dom_struct::dom_struct;
 use servo_arc::Arc;
 use servo_url::ServoUrl;
-use std::ascii::AsciiExt;
 use style::attr::AttrValue;
 use style::properties::{Importance, PropertyDeclarationBlock, PropertyId, LonghandId, ShorthandId};
 use style::properties::{parse_one_declaration_into, parse_style_attribute, SourcePropertyDeclaration};
