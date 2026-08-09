$NetBSD: patch-ui_native__theme_features_native__theme__features.cc,v 1.23 2026/08/09 06:31:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/native_theme/features/native_theme_features.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ ui/native_theme/features/native_theme_features.cc
@@ -46,7 +46,7 @@ bool IsFluentOverlayScrollbarEnabled() {
 
 bool IsFluentScrollbarEnabled() {
 // Fluent scrollbars are only used for some OSes due to UI design guidelines.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
