$NetBSD: patch-servo_components_style_build__gecko.rs,v 1.3 2018/12/12 14:08:50 ryoon Exp $

* Fix build with __uint32_t etc. not found errors on NetBSD/amd64 8.99.2

--- servo/components/style/build_gecko.rs.orig	2018-12-11 15:22:37.369640063 +0000
+++ servo/components/style/build_gecko.rs
@@ -542,6 +542,8 @@ mod bindings {
                 )).mutable_borrowed_type(ty)
                 .zero_size_type(ty, &structs_types);
         }
+        builder = builder
+            .raw_line(format!("pub use gecko_bindings::structs::root::*;"));
         write_binding_file(builder, BINDINGS_FILE, &fixups);
     }
 
