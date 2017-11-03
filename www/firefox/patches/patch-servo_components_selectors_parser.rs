$NetBSD: patch-servo_components_selectors_parser.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/selectors/parser.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/selectors/parser.rs
@@ -1464,7 +1464,7 @@ fn parse_negation<'i, 't, P, E, Impl>(pa
 fn parse_compound_selector<'i, 't, P, E, Impl>(
     parser: &P,
     input: &mut CssParser<'i, 't>,
-    mut builder: &mut SelectorBuilder<Impl>)
+    builder: &mut SelectorBuilder<Impl>)
     -> Result<bool, ParseError<'i, SelectorParseError<'i, E>>>
     where P: Parser<'i, Impl=Impl, Error=E>, Impl: SelectorImpl
 {
