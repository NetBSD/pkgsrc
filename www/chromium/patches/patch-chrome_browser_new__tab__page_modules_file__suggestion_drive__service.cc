$NetBSD: patch-chrome_browser_new__tab__page_modules_file__suggestion_drive__service.cc,v 1.26 2026/09/22 13:41:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc
@@ -38,7 +38,7 @@
 #include "services/network/public/cpp/resource_request.h"
 
 namespace {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kPlatform[] = "LINUX";
 #elif BUILDFLAG(IS_WIN)
 constexpr char kPlatform[] = "WINDOWS";
