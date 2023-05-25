$NetBSD: patch-src_x11__wrapper.rs,v 1.1 2023/05/25 13:50:05 he Exp $

Fix type mismatch:  The third arg to XChangeWindowAttributes() is
a c_ulong, not an u64.

--- src/x11_wrapper.rs.orig	2023-01-02 12:45:40.000000000 +0000
+++ src/x11_wrapper.rs
@@ -434,7 +434,7 @@ pub fn XConvertSelection(
 pub fn XChangeWindowAttributes(
     dpy: Display,
     win: Window,
-    event_mask: u64,
+    event_mask: c_ulong,
     mut attributes: XSetWindowAttributes,
 ) {
     unsafe {
