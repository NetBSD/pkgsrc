$NetBSD: patch-mozilla_servo_components_style_build__gecko.rs,v 1.2 2021/02/08 12:26:20 ryoon Exp $

--- servo/components/style/build_gecko.rs.orig	2020-02-17 23:38:03.000000000 +0000
+++ servo/components/style/build_gecko.rs
@@ -546,6 +546,8 @@ mod bindings {
                 .borrowed_type(ty)
                 .zero_size_type(ty, &structs_types);
         }
+        builder = builder
+            .raw_line(format!("pub use gecko_bindings::structs::root::*;"));
         write_binding_file(builder, BINDINGS_FILE, &fixups);
     }
 
