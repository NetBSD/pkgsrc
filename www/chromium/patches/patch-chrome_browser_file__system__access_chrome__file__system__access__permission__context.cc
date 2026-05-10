$NetBSD: patch-chrome_browser_file__system__access_chrome__file__system__access__permission__context.cc,v 1.19 2026/05/10 15:29:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/file_system_access/chrome_file_system_access_permission_context.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/file_system_access/chrome_file_system_access_permission_context.cc
@@ -411,7 +411,7 @@ GenerateBlockPaths(bool should_normalize
           FILE_PATH_LITERAL("Library/Mobile Documents/com~apple~CloudDocs"),
           BlockType::kDontBlockChildren),
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
       // On Linux also block access to devices via /dev.
       BlockPath::CreateAbsolute(FILE_PATH_LITERAL("/dev"),
                                 BlockType::kBlockAllChildren),
