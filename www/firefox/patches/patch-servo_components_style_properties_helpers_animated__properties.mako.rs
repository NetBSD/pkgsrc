$NetBSD: patch-servo_components_style_properties_helpers_animated__properties.mako.rs,v 1.1 2018/01/24 16:52:08 ryoon Exp $

--- servo/components/style/properties/helpers/animated_properties.mako.rs.orig	2018-01-11 20:16:51.000000000 +0000
+++ servo/components/style/properties/helpers/animated_properties.mako.rs
@@ -12,7 +12,6 @@ use cssparser::Parser;
 #[cfg(feature = "gecko")] use gecko_bindings::structs::nsCSSPropertyID;
 #[cfg(feature = "gecko")] use gecko_bindings::sugar::ownership::{HasFFI, HasSimpleFFI};
 use itertools::{EitherOrBoth, Itertools};
-use num_traits::Zero;
 use properties::{CSSWideKeyword, PropertyDeclaration};
 use properties::longhands;
 use properties::longhands::font_weight::computed_value::T as FontWeight;
