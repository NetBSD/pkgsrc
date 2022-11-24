$NetBSD: patch-src_corelib_qt__cmdline.cmake,v 1.1 2022/11/24 11:11:38 nros Exp $

* support avoiding the cmake archiving api using configure
  cmakes archiving api needs to be avoided since pkgsrc libarchive 
  that cmake uses is built without zstd support

--- src/corelib/qt_cmdline.cmake.orig	2021-02-11 10:23:05.000000000 +0000
+++ src/corelib/qt_cmdline.cmake
@@ -12,3 +12,4 @@ qt_commandline_option(pps TYPE boolean N
 qt_commandline_option(slog2 TYPE boolean)
 qt_commandline_option(syslog TYPE boolean)
 qt_commandline_option(trace TYPE optionalString VALUES etw lttng no yes)
+qt_commandline_option(avoid_cmake_archiving_api TYPE boolean)
