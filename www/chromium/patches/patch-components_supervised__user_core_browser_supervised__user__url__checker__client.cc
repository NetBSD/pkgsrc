$NetBSD: patch-components_supervised__user_core_browser_supervised__user__url__checker__client.cc,v 1.5 2026/10/02 11:43:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/supervised_user/core/browser/supervised_user_url_checker_client.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ components/supervised_user/core/browser/supervised_user_url_checker_client.cc
@@ -66,7 +66,7 @@ void OnResponse(
 
 FetcherConfig GetFetcherConfig(
     bool is_subject_to_family_link_parental_controls) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Supervised users on these platforms might get into a state where their
   // credentials are not available, so best-effort access mode is a graceful
   // fallback here.
