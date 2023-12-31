$NetBSD: patch-display-servers_xlib-display-server_src_xwrap_setters.rs,v 1.1 2023/12/31 08:58:57 pin Exp $

Fix build on i386.
https://github.com/leftwm/leftwm/pull/1202
Discussion: https://github.com/leftwm/leftwm/discussions/1201

--- display-servers/xlib-display-server/src/xwrap/setters.rs.orig	2023-12-31 08:40:24.874175267 +0000
+++ display-servers/xlib-display-server/src/xwrap/setters.rs
@@ -94,7 +94,7 @@ impl XWrap {
 
     /// Sets a desktop property.
     pub fn set_desktop_prop(&self, data: &[u32], atom: c_ulong) {
-        let x_data: Vec<c_long> = data.iter().map(|x| i64::from(*x)).collect();
+        let x_data: Vec<c_long> = data.iter().map(|x| *x as c_long).collect();
         self.replace_property_long(self.root, atom, xlib::XA_CARDINAL, &x_data);
     }
 
