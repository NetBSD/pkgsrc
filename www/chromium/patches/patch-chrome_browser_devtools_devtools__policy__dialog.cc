$NetBSD: patch-chrome_browser_devtools_devtools__policy__dialog.cc,v 1.12 2026/09/22 13:41:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/devtools/devtools_policy_dialog.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/devtools/devtools_policy_dialog.cc
@@ -33,7 +33,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr int kIconPadding = 4;
 #else
 constexpr int kIconPadding = 2;
