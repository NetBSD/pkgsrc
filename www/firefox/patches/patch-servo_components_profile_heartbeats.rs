$NetBSD: patch-servo_components_profile_heartbeats.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/profile/heartbeats.rs.orig	2017-06-15 20:51:55.000000000 +0000
+++ servo/components/profile/heartbeats.rs
@@ -33,7 +33,7 @@ pub fn cleanup() {
         )
     );
     if let Some(mut hbs) = hbs_opt_box {
-        for (_, mut v) in hbs.iter_mut() {
+        for (_, v) in hbs.iter_mut() {
             // log any remaining heartbeat records before dropping
             log_heartbeat_records(v);
         }
@@ -65,7 +65,7 @@ pub fn maybe_heartbeat(category: &Profil
                 if !(*hbs_ptr).contains_key(category) {
                     maybe_create_heartbeat(&mut (*hbs_ptr), category.clone());
                 }
-                if let Some(mut h) = (*hbs_ptr).get_mut(category) {
+                if let Some(h) = (*hbs_ptr).get_mut(category) {
                     (*h).heartbeat(0, 1, start_time, end_time, start_energy, end_energy);
                 }
             }
