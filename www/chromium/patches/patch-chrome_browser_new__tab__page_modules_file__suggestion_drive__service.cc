$NetBSD: patch-chrome_browser_new__tab__page_modules_file__suggestion_drive__service.cc,v 1.31 2026/10/23 15:05:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc
@@ -39,7 +39,7 @@
 #include "services/network/public/cpp/shared_url_loader_factory.h"
 
 namespace {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kPlatform[] = "LINUX";
 #elif BUILDFLAG(IS_WIN)
 constexpr char kPlatform[] = "WINDOWS";
