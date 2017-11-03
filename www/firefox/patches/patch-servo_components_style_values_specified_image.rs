$NetBSD: patch-servo_components_style_values_specified_image.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/style/values/specified/image.rs.orig	2017-09-14 20:15:57.000000000 +0000
+++ servo/components/style/values/specified/image.rs
@@ -686,14 +686,14 @@ impl LineDirection {
         input.try(|i| {
             let to_ident = i.try(|i| i.expect_ident_matching("to"));
             match *compat_mode {
-                /// `to` keyword is mandatory in modern syntax.
+                // `to` keyword is mandatory in modern syntax.
                 CompatMode::Modern => to_ident?,
                 // Fall back to Modern compatibility mode in case there is a `to` keyword.
                 // According to Gecko, `-moz-linear-gradient(to ...)` should serialize like
                 // `linear-gradient(to ...)`.
                 CompatMode::Moz if to_ident.is_ok() => *compat_mode = CompatMode::Modern,
-                /// There is no `to` keyword in webkit prefixed syntax. If it's consumed,
-                /// parsing should throw an error.
+                // There is no `to` keyword in webkit prefixed syntax. If it's consumed,
+                // parsing should throw an error.
                 CompatMode::WebKit if to_ident.is_ok() => {
                     return Err(SelectorParseError::UnexpectedIdent("to".into()).into())
                 },
