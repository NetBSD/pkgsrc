$NetBSD: patch-base_files_drive__info__posix.cc,v 1.1 2025/02/06 09:57:39 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/files/drive_info_posix.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ base/files/drive_info_posix.cc
@@ -28,7 +28,7 @@ DriveInfo& DriveInfo::operator=(DriveInf
 
 std::optional<DriveInfo> GetFileDriveInfo(const FilePath& file_path) {
   DriveInfo drive_info;
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   drive_info.has_seek_penalty = false;
   return drive_info;
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
