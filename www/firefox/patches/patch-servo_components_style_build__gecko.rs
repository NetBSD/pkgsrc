$NetBSD: patch-servo_components_style_build__gecko.rs,v 1.4 2019/01/29 16:28:22 ryoon Exp $

* Fix build with __uint32_t etc. not found errors on NetBSD/amd64 8.99.2

--- servo/components/style/build_gecko.rs.orig	2019-01-18 00:20:49.000000000 +0000
+++ servo/components/style/build_gecko.rs
@@ -559,6 +559,8 @@ mod bindings {
                 .mutable_borrowed_type(ty)
                 .zero_size_type(ty, &structs_types);
         }
+        builder = builder
+            .raw_line(format!("pub use gecko_bindings::structs::root::*;"));
         write_binding_file(builder, BINDINGS_FILE, &fixups);
     }
 
