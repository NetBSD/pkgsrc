$NetBSD: patch-components_constrained__window_constrained__window__views.cc,v 1.8 2025/10/16 19:43:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/constrained_window/constrained_window_views.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ components/constrained_window/constrained_window_views.cc
@@ -380,7 +380,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
