$NetBSD: patch-ui_native__theme_features_native__theme__features.cc,v 1.5 2025/09/08 13:24:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/native_theme/features/native_theme_features.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ ui/native_theme/features/native_theme_features.cc
@@ -54,7 +54,7 @@ namespace ui {
 
 bool IsFluentOverlayScrollbarEnabled() {
 // Fluent scrollbars are only used for some OSes due to UI design guidelines.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(features::kFluentOverlayScrollbar);
 #else
   return false;
@@ -63,7 +63,7 @@ bool IsFluentOverlayScrollbarEnabled() {
 
 bool IsFluentScrollbarEnabled() {
 // Fluent scrollbars are only used for some OSes due to UI design guidelines.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(features::kFluentScrollbar) ||
          IsFluentOverlayScrollbarEnabled();
 #else
