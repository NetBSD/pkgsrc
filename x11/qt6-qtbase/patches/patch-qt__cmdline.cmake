$NetBSD: patch-qt__cmdline.cmake,v 1.1 2025/11/11 12:34:13 adam Exp $

Add support for avoiding the cmake archiving api using configure since
libarchive in pkgsrc that cmake uses is built without zstd support.

--- qt_cmdline.cmake.orig	2025-11-09 11:48:20.825810916 +0000
+++ qt_cmdline.cmake
@@ -44,6 +44,7 @@ qt_commandline_option(android-javac-sour
 )
 qt_commandline_option(android-style-assets TYPE boolean)
 qt_commandline_option(appstore-compliant TYPE boolean)
+qt_commandline_option(avoid_cmake_archiving_api TYPE boolean CMAKE_VARIABLE QT_AVOID_CMAKE_ARCHIVING_API)
 qt_commandline_option(avx TYPE boolean)
 qt_commandline_option(avx2 TYPE boolean)
 qt_commandline_option(avx512 TYPE boolean NAME avx512f)
