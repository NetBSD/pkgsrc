$NetBSD: patch-servo_components_style_build__gecko.rs,v 1.2 2018/11/04 00:38:45 ryoon Exp $

* Fix build with __uint32_t etc. not found errors on NetBSD/amd64 8.99.2

--- servo/components/style/build_gecko.rs.orig	2018-10-18 20:06:10.000000000 +0000
+++ servo/components/style/build_gecko.rs
@@ -557,6 +557,8 @@ mod bindings {
                 .borrowed_type(ty)
                 .zero_size_type(ty, &structs_types);
         }
+        builder = builder
+            .raw_line(format!("pub use gecko_bindings::structs::root::*;"));
         write_binding_file(builder, BINDINGS_FILE, &fixups);
     }
 
