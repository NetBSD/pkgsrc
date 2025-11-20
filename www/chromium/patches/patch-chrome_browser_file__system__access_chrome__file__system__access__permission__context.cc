$NetBSD: patch-chrome_browser_file__system__access_chrome__file__system__access__permission__context.cc,v 1.10 2025/11/20 08:36:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/file_system_access/chrome_file_system_access_permission_context.cc.orig	2025-11-14 20:31:45.000000000 +0000
+++ chrome/browser/file_system_access/chrome_file_system_access_permission_context.cc
@@ -377,7 +377,7 @@ GenerateBlockPaths(bool should_normalize
            FILE_PATH_LITERAL("Library/Mobile Documents/com~apple~CloudDocs"),
            BlockType::kDontBlockChildren},
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
           // On Linux also block access to devices via /dev.
           {kNoBasePathKey, FILE_PATH_LITERAL("/dev"),
            BlockType::kBlockAllChildren},
