$NetBSD: patch-src_3rdparty_chromium_components_constrained__window_constrained__window__views.cc,v 1.1 2025/12/21 09:38:21 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/constrained_window/constrained_window_views.cc.orig	2025-11-14 07:55:10.000000000 +0000
+++ src/3rdparty/chromium/components/constrained_window/constrained_window_views.cc
@@ -375,7 +375,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
