$NetBSD: patch-servo_components_script_dom_cssstylerule.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/script/dom/cssstylerule.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/script/dom/cssstylerule.rs
@@ -99,7 +99,7 @@ impl CSSStyleRuleMethods for CSSStyleRul
         if let Ok(mut s) = SelectorList::parse(&parser, &mut css_parser) {
             // This mirrors what we do in CSSStyleOwner::mutate_associated_block.
             let mut guard = self.cssrule.shared_lock().write();
-            let mut stylerule = self.stylerule.write_with(&mut guard);
+            let stylerule = self.stylerule.write_with(&mut guard);
             mem::swap(&mut stylerule.selectors, &mut s);
             // It seems like we will want to avoid having to invalidate all
             // stylesheets eventually!
