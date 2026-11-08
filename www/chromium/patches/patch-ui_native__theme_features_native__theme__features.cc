$NetBSD: patch-ui_native__theme_features_native__theme__features.cc,v 1.31 2026/11/08 15:39:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/native_theme/features/native_theme_features.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ ui/native_theme/features/native_theme_features.cc
@@ -62,7 +62,7 @@ bool IsFluentOverlayScrollbarEnabled() {
 
 bool IsFluentScrollbarEnabled() {
 // Fluent scrollbars are only used for some OSes due to UI design guidelines.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
