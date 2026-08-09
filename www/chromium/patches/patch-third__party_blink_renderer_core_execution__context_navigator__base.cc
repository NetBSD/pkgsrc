$NetBSD: patch-third__party_blink_renderer_core_execution__context_navigator__base.cc,v 1.24 2026/08/09 06:31:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/execution_context/navigator_base.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ third_party/blink/renderer/core/execution_context/navigator_base.cc
@@ -32,7 +32,7 @@ String GetReducedNavigatorPlatform() {
   return "Win32";
 #elif BUILDFLAG(IS_FUCHSIA)
   return "";
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return "Linux x86_64";
 #elif BUILDFLAG(IS_IOS)
   return "iPhone";
