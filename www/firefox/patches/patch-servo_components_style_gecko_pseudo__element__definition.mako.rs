$NetBSD: patch-servo_components_style_gecko_pseudo__element__definition.mako.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/style/gecko/pseudo_element_definition.mako.rs.orig	2017-11-02 16:16:33.000000000 +0000
+++ servo/components/style/gecko/pseudo_element_definition.mako.rs
@@ -186,7 +186,6 @@ impl PseudoElement {
     /// Returns `None` if the pseudo-element is not recognised.
     #[inline]
     pub fn from_slice(s: &str, in_ua_stylesheet: bool) -> Option<Self> {
-        use std::ascii::AsciiExt;
 
         // We don't need to support tree pseudos because functional
         // pseudo-elements needs arguments, and thus should be created
@@ -208,7 +207,6 @@ impl PseudoElement {
     /// Returns `None` if the pseudo-element is not recognized.
     #[inline]
     pub fn tree_pseudo_element(name: &str, args: Box<[String]>) -> Option<Self> {
-        use std::ascii::AsciiExt;
         debug_assert!(name.starts_with("-moz-tree-"));
         let tree_part = &name[10..];
         % for pseudo in TREE_PSEUDOS:
