$NetBSD: patch-servo_tests_unit_style_stylist.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/tests/unit/style/stylist.rs.orig	2017-09-14 20:15:57.000000000 +0000
+++ servo/tests/unit/style/stylist.rs
@@ -51,19 +51,6 @@ fn get_mock_rules(css_selectors: &[&str]
     }).collect(), shared_lock)
 }
 
-fn get_mock_map(selectors: &[&str]) -> (SelectorMap<Rule>, SharedRwLock) {
-    let mut map = SelectorMap::<Rule>::new();
-    let (selector_rules, shared_lock) = get_mock_rules(selectors);
-
-    for rules in selector_rules.into_iter() {
-        for rule in rules.into_iter() {
-            map.insert(rule, QuirksMode::NoQuirks)
-        }
-    }
-
-    (map, shared_lock)
-}
-
 fn parse_selectors(selectors: &[&str]) -> Vec<Selector<SelectorImpl>> {
     selectors.iter()
              .map(|x| SelectorParser::parse_author_origin_no_namespace(x).unwrap().0
