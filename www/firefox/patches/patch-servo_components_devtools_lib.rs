$NetBSD: patch-servo_components_devtools_lib.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/devtools/lib.rs.orig	2017-09-14 20:15:55.000000000 +0000
+++ servo/components/devtools/lib.rs
@@ -306,7 +306,7 @@ fn run_server(sender: Sender<DevtoolsCon
                 columnNumber: console_message.columnNumber,
             },
         };
-        for mut stream in &mut *console_actor.streams.borrow_mut() {
+        for stream in &mut *console_actor.streams.borrow_mut() {
             stream.write_json_packet(&msg);
         }
     }
