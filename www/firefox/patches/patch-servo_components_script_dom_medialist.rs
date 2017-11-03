$NetBSD: patch-servo_components_script_dom_medialist.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/script/dom/medialist.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/script/dom/medialist.rs
@@ -63,7 +63,7 @@ impl MediaListMethods for MediaList {
     // https://drafts.csswg.org/cssom/#dom-medialist-mediatext
     fn SetMediaText(&self, value: DOMString) {
         let mut guard = self.shared_lock().write();
-        let mut media_queries = self.media_queries.write_with(&mut guard);
+        let media_queries = self.media_queries.write_with(&mut guard);
         // Step 2
         if value.is_empty() {
             // Step 1
@@ -154,7 +154,7 @@ impl MediaListMethods for MediaList {
         // Step 3
         let m_serialized = m.unwrap().to_css_string();
         let mut guard = self.shared_lock().write();
-        let mut media_list = self.media_queries.write_with(&mut guard);
+        let media_list = self.media_queries.write_with(&mut guard);
         let new_vec = media_list.media_queries.drain(..)
                                 .filter(|q| m_serialized != q.to_css_string())
                                 .collect();
