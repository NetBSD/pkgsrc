$NetBSD: patch-chrome_browser_devtools_devtools__policy__dialog.cc,v 1.1 2026/02/15 09:03:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/devtools/devtools_policy_dialog.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/devtools/devtools_policy_dialog.cc
@@ -32,7 +32,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr int kIconPadding = 4;
 #else
 constexpr int kIconPadding = 2;
