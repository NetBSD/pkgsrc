$NetBSD: patch-chrome_browser_devtools_devtools__policy__dialog.cc,v 1.18 2026/11/08 15:38:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/devtools/devtools_policy_dialog.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/devtools/devtools_policy_dialog.cc
@@ -38,7 +38,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr int kIconPadding = 4;
 #else
 constexpr int kIconPadding = 2;
