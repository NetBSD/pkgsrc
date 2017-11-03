$NetBSD: patch-servo_components_layout_inline.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/layout/inline.rs.orig	2017-09-14 20:15:55.000000000 +0000
+++ servo/components/layout/inline.rs
@@ -435,7 +435,7 @@ impl LineBreaker {
             return
         }
         let last_fragment_index = self.pending_line.range.end() - FragmentIndex(1);
-        let mut fragment = &mut self.new_fragments[last_fragment_index.get() as usize];
+        let fragment = &mut self.new_fragments[last_fragment_index.get() as usize];
 
         let old_fragment_inline_size = fragment.border_box.size.inline;
 
@@ -1047,7 +1047,7 @@ impl InlineFlow {
         let space_per_expansion_opportunity = slack_inline_size / expansion_opportunities as i32;
         for fragment_index in line.range.each_index() {
             let fragment = fragments.get_mut(fragment_index.to_usize());
-            let mut scanned_text_fragment_info = match fragment.specific {
+            let scanned_text_fragment_info = match fragment.specific {
                 SpecificFragmentInfo::ScannedText(ref mut info) if !info.range.is_empty() => info,
                 _ => continue
             };
