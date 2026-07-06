$NetBSD: patch-components_constrained__window_constrained__window__views.cc,v 1.22 2026/07/06 13:06:48 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/constrained_window/constrained_window_views.cc.orig	2026-06-23 23:37:18.000000000 +0000
+++ components/constrained_window/constrained_window_views.cc
@@ -413,7 +413,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
