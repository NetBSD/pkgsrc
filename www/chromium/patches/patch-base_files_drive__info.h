$NetBSD: patch-base_files_drive__info.h,v 1.8 2025/10/16 19:43:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/files/drive_info.h.orig	2025-10-13 21:41:26.000000000 +0000
+++ base/files/drive_info.h
@@ -48,7 +48,7 @@ struct BASE_EXPORT DriveInfo {
   std::optional<bool> has_seek_penalty;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Whether the drive is a "removable" drive.
   //
   // In macOS's IOKit API, a drive is "removable" if "the media is removable
