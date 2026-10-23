$NetBSD: patch-third__party_blink_renderer_core_execution__context_navigator__base.cc,v 1.31 2026/10/23 15:05:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/execution_context/navigator_base.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ third_party/blink/renderer/core/execution_context/navigator_base.cc
@@ -27,7 +27,7 @@ namespace blink {
 
 namespace {
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 constexpr char kLinuxX86_64[] = "Linux x86_64";
 #endif
 
@@ -47,7 +47,7 @@ String GetReducedNavigatorPlatform() {
   return "Win32";
 #elif BUILDFLAG(IS_FUCHSIA)
   return "";
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return kLinuxX86_64;
 #elif BUILDFLAG(IS_IOS)
   return "iPhone";
