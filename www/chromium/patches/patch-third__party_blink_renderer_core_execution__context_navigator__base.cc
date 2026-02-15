$NetBSD: patch-third__party_blink_renderer_core_execution__context_navigator__base.cc,v 1.15 2026/02/15 09:04:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/execution_context/navigator_base.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ third_party/blink/renderer/core/execution_context/navigator_base.cc
@@ -31,7 +31,7 @@ String GetReducedNavigatorPlatform() {
   return "Win32";
 #elif BUILDFLAG(IS_FUCHSIA)
   return "";
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return "Linux x86_64";
 #elif BUILDFLAG(IS_IOS)
   return "iPhone";
