$NetBSD: patch-third-party_rust_authenticator_src_transport_netbsd_device.rs,v 1.1 2023/04/28 18:56:22 maya Exp $

Apply already-upstreamed fix to authenticator-rs:
https://github.com/mozilla/authenticator-rs/pull/234

Fixing netbsd support

--- third_party/rust/authenticator/src/transport/netbsd/device.rs.orig	2023-04-14 16:28:09.000000000 +0000
+++ third_party/rust/authenticator/src/transport/netbsd/device.rs
@@ -40,7 +40,19 @@ impl Device {
             buf[6] = 0;
             buf[7] = 1; // one byte
 
-            self.write_all(&buf)?;
+            // Write ping request.  Each write to the device contains
+            // exactly one report id byte[*] followed by exactly as
+            // many bytes as are in a report, and will be consumed all
+            // at once by /dev/uhidN.  So we use plain write, not
+            // write_all to issue writes in a loop.
+            //
+            // [*] This is only for the internal authenticator-rs API,
+            // not for the USB HID protocol, which for a device with
+            // only one report id excludes the report id byte from the
+            // interrupt in/out pipe transfer format.
+            if self.write(&buf)? != buf.len() {
+                return Err(io_err("write ping failed"));
+            }
 
             // Wait for response
             let mut pfd: libc::pollfd = unsafe { mem::zeroed() };
@@ -55,8 +67,13 @@ impl Device {
                 continue;
             }
 
-            // Read response
-            self.read_exact(&mut buf)?;
+            // Read response.  When reports come in they are all
+            // exactly the same size, with no report id byte because
+            // there is only one report.
+            let n = self.read(&mut buf[1..])?;
+            if n != buf.len() - 1 {
+                return Err(io_err("read pong failed"));
+            }
 
             return Ok(());
         }
