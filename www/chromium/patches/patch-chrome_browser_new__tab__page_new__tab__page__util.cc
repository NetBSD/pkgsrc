$NetBSD: patch-chrome_browser_new__tab__page_new__tab__page__util.cc,v 1.5 2025/08/13 07:44:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/new_tab_page/new_tab_page_util.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ chrome/browser/new_tab_page/new_tab_page_util.cc
@@ -32,7 +32,7 @@ bool IsOsSupportedForCart() {
 }
 
 bool IsOsSupportedForDrive() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
