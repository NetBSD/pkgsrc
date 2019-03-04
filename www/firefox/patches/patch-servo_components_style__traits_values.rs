$NetBSD: patch-servo_components_style__traits_values.rs,v 1.1 2019/03/04 15:53:06 ryoon Exp $

* Fix build with lang/rust-1.33.0

--- servo/components/style_traits/values.rs.orig	2019-02-27 22:18:28.000000000 +0000
+++ servo/components/style_traits/values.rs
@@ -450,7 +432,7 @@ impl_to_css_for_predefined_type!(::csspa
 impl_to_css_for_predefined_type!(::cssparser::Color);
 impl_to_css_for_predefined_type!(::cssparser::UnicodeRange);
 
-#[macro_export]
+/// Define an enum type with unit variants that each corrsepond to a CSS keyword.
 macro_rules! define_css_keyword_enum {
     (pub enum $name:ident { $($variant:ident = $css:expr,)+ }) => {
         #[allow(missing_docs)]
