$NetBSD: patch-src_x11__wrapper.rs,v 1.2 2024/01/20 23:27:51 he Exp $

Fix type mismatch:  The third arg to XChangeWindowAttributes() is
a c_ulong, not an u64.
Comment out unused import.

--- src/x11_wrapper.rs.orig	2023-01-02 12:45:40.000000000 +0000
+++ src/x11_wrapper.rs
@@ -32,7 +32,7 @@ pub use xlib::True;
 pub use xlib::Window;
 pub use xlib::XEvent;
 pub use xlib::XGCValues;
-pub use xlib::XICCEncodingStyle;
+// pub use xlib::XICCEncodingStyle; (unused)
 pub use xlib::XSetWindowAttributes;
 pub use xlib::XTextProperty;
 pub use xlib::XUTF8StringStyle;
@@ -434,7 +434,7 @@ pub fn XConvertSelection(
 pub fn XChangeWindowAttributes(
     dpy: Display,
     win: Window,
-    event_mask: u64,
+    event_mask: c_ulong,
     mut attributes: XSetWindowAttributes,
 ) {
     unsafe {
