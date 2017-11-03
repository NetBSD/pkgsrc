$NetBSD: patch-servo_components_layout_display__list__builder.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/layout/display_list_builder.rs.orig	2017-09-14 20:15:55.000000000 +0000
+++ servo/components/layout/display_list_builder.rs
@@ -2718,7 +2718,7 @@ impl InlineFlowDisplayListBuilding for I
         self.base.scroll_root_id = Some(state.current_scroll_root_id);
         self.base.clip = state.clip_stack.last().cloned().unwrap_or_else(max_rect);
 
-        for mut fragment in self.fragments.fragments.iter_mut() {
+        for fragment in self.fragments.fragments.iter_mut() {
             let previous_containing_block_scroll_root_id = state.containing_block_scroll_root_id;
             if establishes_containing_block_for_absolute(fragment.style.get_box().position) {
                 state.containing_block_scroll_root_id = state.current_scroll_root_id;
