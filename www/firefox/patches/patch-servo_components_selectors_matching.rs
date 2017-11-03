$NetBSD: patch-servo_components_selectors_matching.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/selectors/matching.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/selectors/matching.rs
@@ -458,7 +458,7 @@ where
 /// Matches a complex selector.
 pub fn matches_complex_selector<E, F>(mut iter: SelectorIter<E::Impl>,
                                       element: &E,
-                                      mut context: &mut LocalMatchingContext<E::Impl>,
+                                      context: &mut LocalMatchingContext<E::Impl>,
                                       flags_setter: &mut F)
                                       -> bool
     where E: Element,
