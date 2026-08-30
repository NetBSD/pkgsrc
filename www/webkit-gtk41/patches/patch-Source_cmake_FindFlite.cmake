$NetBSD: patch-Source_cmake_FindFlite.cmake,v 1.1 2026/08/30 14:25:06 wiz Exp $

* Fix link with static flite libraries

us_ffeatures.c:(.text+0x70e): undefined reference to `basic_ff_register'
cmu_us_kal.c:(.text+0x175): undefined reference to `diphone_synth'
cmu_us_kal.c:(.text+0x19d): undefined reference to `diphone_db_val'


--- Source/cmake/FindFlite.cmake.orig	2025-05-17 09:37:11.308174217 +0000
+++ Source/cmake/FindFlite.cmake
@@ -141,7 +141,6 @@ mark_as_advanced(
 
 if (Flite_FOUND)
     set(Flite_LIBRARIES
-        ${Flite_LIBRARY}
         ${Flite_Usenglish_LIBRARY}
         ${Flite_Cmu_Grapheme_Lang_LIBRARY}
         ${Flite_Cmu_Grapheme_Lex_LIBRARY}
@@ -154,6 +153,7 @@ if (Flite_FOUND)
         ${Flite_Cmu_Us_Kal_LIBRARY}
         ${Flite_Cmu_Us_Rms_LIBRARY}
         ${Flite_Cmu_Us_Slt_LIBRARY}
+        ${Flite_LIBRARY}
     )
     set(Flite_INCLUDE_DIRS ${Flite_INCLUDE_DIR})
 endif ()
