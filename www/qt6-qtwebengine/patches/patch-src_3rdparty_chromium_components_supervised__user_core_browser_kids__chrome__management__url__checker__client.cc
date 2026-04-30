$NetBSD: patch-src_3rdparty_chromium_components_supervised__user_core_browser_kids__chrome__management__url__checker__client.cc,v 1.1 2026/04/30 06:39:39 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/supervised_user/core/browser/kids_chrome_management_url_checker_client.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/supervised_user/core/browser/kids_chrome_management_url_checker_client.cc
@@ -66,7 +66,7 @@ void OnResponse(
 }
 
 FetcherConfig GetFetcherConfig(bool is_subject_to_parental_controls) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Supervised users on these platforms might get into a state where their
   // credentials are not available, so best-effort access mode is a graceful
   // fallback here.
