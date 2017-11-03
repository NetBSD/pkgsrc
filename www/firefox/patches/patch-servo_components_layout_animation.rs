$NetBSD: patch-servo_components_layout_animation.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/layout/animation.rs.orig	2017-09-14 20:15:55.000000000 +0000
+++ servo/components/layout/animation.rs
@@ -39,7 +39,7 @@ pub fn update_animation_state(constellat
             // run.
             if let Some(ref mut animations) = running_animations.get_mut(node) {
                 // TODO: This being linear is probably not optimal.
-                for mut anim in animations.iter_mut() {
+                for anim in animations.iter_mut() {
                     if let Animation::Keyframes(_, ref anim_name, ref mut anim_state) = *anim {
                         if *name == *anim_name {
                             debug!("update_animation_state: Found other animation {}", name);
