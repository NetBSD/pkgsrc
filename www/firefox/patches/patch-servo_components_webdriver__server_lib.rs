$NetBSD: patch-servo_components_webdriver__server_lib.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/webdriver_server/lib.rs.orig	2017-09-14 20:15:57.000000000 +0000
+++ servo/components/webdriver_server/lib.rs
@@ -702,7 +702,7 @@ impl Handler {
     fn handle_set_timeouts(&mut self,
                            parameters: &TimeoutsParameters)
                            -> WebDriverResult<WebDriverResponse> {
-        let mut session = self.session
+        let session = self.session
             .as_mut()
             .ok_or(WebDriverError::new(ErrorStatus::SessionNotCreated, ""))?;
 
