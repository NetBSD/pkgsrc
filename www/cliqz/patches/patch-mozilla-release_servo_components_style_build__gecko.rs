$NetBSD: patch-mozilla-release_servo_components_style_build__gecko.rs,v 1.1 2019/04/19 14:02:03 fox Exp $

* Fix build with __uint32_t etc. not found errors on NetBSD/amd64 8.99.2

Original patch from ryoon, imported from www/firefox

--- mozilla-release/servo/components/style/build_gecko.rs.orig	2018-11-16 08:40:07.000000000 +0000
+++ mozilla-release/servo/components/style/build_gecko.rs
@@ -559,6 +559,8 @@ mod bindings {
                 .mutable_borrowed_type(ty)
                 .zero_size_type(ty, &structs_types);
         }
+        builder = builder
+            .raw_line(format!("pub use gecko_bindings::structs::root::*;"));
         write_binding_file(builder, BINDINGS_FILE, &fixups);
     }
 
