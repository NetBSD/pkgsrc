$NetBSD: patch-src_3rdparty_gn_tools_gn_ninja_binary_target_writer.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

support writing out -L/foo -Wl,-R/foo

--- src/3rdparty/gn/tools/gn/ninja_binary_target_writer.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/gn/tools/gn/ninja_binary_target_writer.cc
@@ -260,6 +260,9 @@ void NinjaBinaryTargetWriter::WriteLinke
       out << " " << tool->lib_dir_switch();
       lib_path_output.WriteDir(out, all_lib_dirs[i],
                                PathOutput::DIR_NO_LAST_SLASH);
+      out << " " << tool->lib_dir_Rswitch();
+      lib_path_output.WriteDir(out, all_lib_dirs[i],
+                               PathOutput::DIR_NO_LAST_SLASH);
     }
   }
 
