$NetBSD: patch-components_supervised__user_core_browser_supervised__user__utils.cc,v 1.4 2026/05/10 15:29:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/supervised_user/core/browser/supervised_user_utils.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/supervised_user/core/browser/supervised_user_utils.cc
@@ -42,7 +42,7 @@ constexpr char kParentAccessResultQueryP
 constexpr char kPacpOriginUrlHost[] = "families.google.com";
 
 #if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Returns the text that will be shown as the PACP widget subtitle, containing
 // information about the blocked hostname and the blocking reason.
 std::string GetBlockingReasonSubtitle(
@@ -187,7 +187,7 @@ GURL NormalizeUrl(const GURL& url) {
 }
 
 #if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 GURL GetParentAccessURL(
     const std::string& locale,
     const GURL& blocked_url,
@@ -202,7 +202,7 @@ GURL GetParentAccessURL(
   // Caller Ids for Desktop and iOS platforms.
 #if BUILDFLAG(IS_IOS)
   static constexpr char kCallerId[] = "qSTnVRdQ";
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   static constexpr char kCallerId[] = "clwAA5XJ";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
