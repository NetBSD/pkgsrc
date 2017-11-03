$NetBSD: patch-servo_components_net_cookie__storage.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/net/cookie_storage.rs.orig	2017-07-31 16:20:53.000000000 +0000
+++ servo/components/net/cookie_storage.rs
@@ -103,7 +103,7 @@ impl CookieStorage {
 
         // Step 12
         let domain = reg_host(&cookie.cookie.domain().as_ref().unwrap_or(&""));
-        let mut cookies = self.cookies_map.entry(domain).or_insert(vec![]);
+        let cookies = self.cookies_map.entry(domain).or_insert(vec![]);
 
         if cookies.len() == self.max_per_host {
             let old_len = cookies.len();
