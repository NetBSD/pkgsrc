$NetBSD: patch-sql_database.cc,v 1.13 2026/07/08 13:42:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- sql/database.cc.orig	2026-07-06 22:58:46.000000000 +0000
+++ sql/database.cc
@@ -118,7 +118,7 @@ bool FilePathIsFixedSSD(const base::File
 
   return !drive_info->has_seek_penalty.value_or(false)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
          && !drive_info->is_removable.value_or(false)
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
