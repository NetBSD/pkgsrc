$NetBSD: patch-mozilla_toolkit_mozapps_update_updater_updater.cpp,v 1.1 2013/08/30 13:00:37 joerg Exp $

--- mozilla/toolkit/mozapps/update/updater/updater.cpp.orig	2013-08-04 03:05:52.000000000 +0000
+++ mozilla/toolkit/mozapps/update/updater/updater.cpp
@@ -123,7 +123,10 @@ static bool sUseHardLinks = true;
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
