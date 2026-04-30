$NetBSD: patch-src_3rdparty_chromium_components_supervised__user_core_browser_list__family__members__service.h,v 1.1 2026/04/30 06:39:39 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/supervised_user/core/browser/list_family_members_service.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/supervised_user/core/browser/list_family_members_service.h
@@ -33,7 +33,7 @@ namespace supervised_user {
 // If true, this fetcher is active for all users with CanFetchFamilyMemberInfo
 // capability. Otherwise, it is only used by supervised users.
 constexpr bool FetchListFamilyMembersWithCapability() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
