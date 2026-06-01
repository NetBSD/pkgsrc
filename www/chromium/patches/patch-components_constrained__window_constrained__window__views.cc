$NetBSD: patch-components_constrained__window_constrained__window__views.cc,v 1.20 2026/06/01 10:09:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/constrained_window/constrained_window_views.cc.orig	2026-05-26 20:39:02.000000000 +0000
+++ components/constrained_window/constrained_window_views.cc
@@ -380,7 +380,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
