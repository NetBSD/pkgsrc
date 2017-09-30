$NetBSD: patch-servo_components_style_build__gecko.rs,v 1.1 2017/09/30 05:34:12 ryoon Exp $

* Fix build with __uint32_t etc. not found errors on NetBSD/amd64 8.99.2

--- servo/components/style/build_gecko.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/style/build_gecko.rs
@@ -546,6 +546,8 @@ mod bindings {
                 .borrowed_type(ty)
                 .zero_size_type(ty, &structs_types);
         }
+        builder = builder
+            .raw_line(format!("pub use gecko_bindings::structs::root::*;"));
         write_binding_file(builder, BINDINGS_FILE, &fixups);
     }
 
