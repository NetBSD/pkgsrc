$NetBSD: patch-src_3rdparty_gn_src_gn_ninja__binary__target__writer.cc,v 1.1 2025/12/21 09:38:51 markd Exp $

support writing out -L/foo -Wl,-R/foo

--- src/3rdparty/gn/src/gn/ninja_binary_target_writer.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/gn/src/gn/ninja_binary_target_writer.cc
@@ -336,6 +336,9 @@ void NinjaBinaryTargetWriter::WriteLibra
       out << " " << tool->lib_dir_switch();
       lib_path_output.WriteDir(out, all_lib_dirs[i],
                                PathOutput::DIR_NO_LAST_SLASH);
+      out << " " << tool->lib_dir_Rswitch();
+      lib_path_output.WriteDir(out, all_lib_dirs[i],
+                               PathOutput::DIR_NO_LAST_SLASH);
     }
   }
 
