$NetBSD: patch-toolkit_mozapps_update_updater_updater.cpp,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- toolkit/mozapps/update/updater/updater.cpp.orig	2014-01-28 04:04:06.000000000 +0000
+++ toolkit/mozapps/update/updater/updater.cpp
@@ -127,7 +127,10 @@ static bool sUseHardLinks = true;
 // declare it here to avoid including that entire header file.
 #define BZ2_CRC32TABLE_UNDECLARED
 
-#if MOZ_IS_GCC
+#if defined(__clang__)
+extern "C"  __attribute__((visibility("default"))) unsigned int BZ2_crc32Table[256];
+#undef BZ2_CRC32TABLE_UNDECLARED
+#elif MOZ_IS_GCC
 #if MOZ_GCC_VERSION_AT_LEAST(3, 3, 0)
 extern "C"  __attribute__((visibility("default"))) unsigned int BZ2_crc32Table[256];
 #undef BZ2_CRC32TABLE_UNDECLARED
