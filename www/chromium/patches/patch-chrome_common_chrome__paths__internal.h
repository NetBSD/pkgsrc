$NetBSD: patch-chrome_common_chrome__paths__internal.h,v 1.14 2026/01/19 16:14:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/chrome_paths_internal.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/common/chrome_paths_internal.h
@@ -53,7 +53,7 @@ void GetUserCacheDirectory(const base::F
 // Get the path to the user's documents directory.
 bool GetUserDocumentsDirectory(base::FilePath* result);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Gets the path to a safe default download directory for a user.
 bool GetUserDownloadsDirectorySafe(base::FilePath* result);
 #endif
