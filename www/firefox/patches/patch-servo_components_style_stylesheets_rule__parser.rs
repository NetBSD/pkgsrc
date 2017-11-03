$NetBSD: patch-servo_components_style_stylesheets_rule__parser.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/style/stylesheets/rule_parser.rs.orig	2017-09-14 20:15:57.000000000 +0000
+++ servo/components/style/stylesheets/rule_parser.rs
@@ -209,7 +209,7 @@ impl<'a, 'i> AtRuleParser<'i> for TopLev
                 let id = register_namespace(&url)
                     .map_err(|()| StyleParseError::UnspecifiedError)?;
 
-                let mut namespaces = self.namespaces.as_mut().unwrap();
+                let namespaces = self.namespaces.as_mut().unwrap();
 
                 let opt_prefix = if let Ok(prefix) = prefix_result {
                     let prefix = Prefix::from(prefix.as_ref());
