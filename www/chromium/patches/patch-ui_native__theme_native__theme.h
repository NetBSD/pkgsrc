$NetBSD: patch-ui_native__theme_native__theme.h,v 1.10 2025/11/20 08:36:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/native_theme/native_theme.h.orig	2025-11-14 20:31:45.000000000 +0000
+++ ui/native_theme/native_theme.h
@@ -61,7 +61,7 @@ class COMPONENT_EXPORT(NATIVE_THEME) Nat
   // A part being sized or painted.
   enum Part {
     kCheckbox,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     kFrameTopArea,
 #endif
     kInnerSpinButton,
