$NetBSD: patch-chrome_browser_new__tab__page_new__tab__page__util.cc,v 1.10 2025/11/20 08:36:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/new_tab_page/new_tab_page_util.cc.orig	2025-11-14 20:31:45.000000000 +0000
+++ chrome/browser/new_tab_page/new_tab_page_util.cc
@@ -35,7 +35,7 @@ bool IsOsSupportedForCart() {
 }
 
 bool IsOsSupportedForDrive() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
