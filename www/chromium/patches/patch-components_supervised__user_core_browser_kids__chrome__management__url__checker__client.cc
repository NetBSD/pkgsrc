$NetBSD: patch-components_supervised__user_core_browser_kids__chrome__management__url__checker__client.cc,v 1.5 2025/11/04 14:55:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/supervised_user/core/browser/kids_chrome_management_url_checker_client.cc.orig	2025-10-24 16:42:30.000000000 +0000
+++ components/supervised_user/core/browser/kids_chrome_management_url_checker_client.cc
@@ -66,7 +66,7 @@ void OnResponse(
 }
 
 FetcherConfig GetFetcherConfig(bool is_subject_to_parental_controls) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Supervised users on these platforms might get into a state where their
   // credentials are not available, so best-effort access mode is a graceful
   // fallback here.
