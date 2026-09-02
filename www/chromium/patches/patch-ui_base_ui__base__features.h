$NetBSD: patch-ui_base_ui__base__features.h,v 1.11 2026/09/02 13:13:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/ui_base_features.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ ui/base/ui_base_features.h
@@ -152,7 +152,7 @@ COMPONENT_EXPORT(UI_BASE_FEATURES)
 BASE_DECLARE_FEATURE(kWaylandExternalBeginFrameSource);
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 BASE_DECLARE_FEATURE(kGlobalShortcutsPortalPreferredTrigger);
 #endif
