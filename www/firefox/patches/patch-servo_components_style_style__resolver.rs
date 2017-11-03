$NetBSD: patch-servo_components_style_style__resolver.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/style/style_resolver.rs.orig	2017-09-14 20:15:57.000000000 +0000
+++ servo/components/style/style_resolver.rs
@@ -247,7 +247,7 @@ where
                         Some(&*primary_style.style)
                     };
 
-                for (i, mut inputs) in pseudo_array.iter_mut().enumerate() {
+                for (i, inputs) in pseudo_array.iter_mut().enumerate() {
                     if let Some(inputs) = inputs.take() {
                         let pseudo = PseudoElement::from_eager_index(i);
                         pseudo_styles.set(
