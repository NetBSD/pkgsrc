$NetBSD: patch-ui_native__theme_native__theme.h,v 1.27 2026/09/29 07:43:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/native_theme/native_theme.h.orig	2026-09-22 00:09:16.000000000 +0000
+++ ui/native_theme/native_theme.h
@@ -64,7 +64,7 @@ class COMPONENT_EXPORT(NATIVE_THEME) Nat
   // A part being sized or painted.
   enum Part {
     kCheckbox,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     kFrameTopArea,
 #endif
     kInnerSpinButton,
