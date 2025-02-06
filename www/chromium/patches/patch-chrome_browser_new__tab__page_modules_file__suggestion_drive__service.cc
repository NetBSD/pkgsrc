$NetBSD: patch-chrome_browser_new__tab__page_modules_file__suggestion_drive__service.cc,v 1.1 2025/02/06 09:57:49 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc
@@ -34,7 +34,7 @@
 #include "services/network/public/cpp/resource_request.h"
 
 namespace {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kPlatform[] = "LINUX";
 #elif BUILDFLAG(IS_WIN)
 constexpr char kPlatform[] = "WINDOWS";
