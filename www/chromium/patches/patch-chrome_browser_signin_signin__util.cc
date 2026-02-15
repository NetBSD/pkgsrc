$NetBSD: patch-chrome_browser_signin_signin__util.cc,v 1.15 2026/02/15 09:03:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/signin/signin_util.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/signin/signin_util.cc
@@ -49,7 +49,7 @@
 #include "services/network/public/mojom/cookie_manager.mojom.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_dialogs.h"
 #include "chrome/browser/ui/browser_finder.h"
 #include "components/strings/grit/components_strings.h"
@@ -100,7 +100,7 @@ CookiesMover::CookiesMover(base::WeakPtr
 CookiesMover::~CookiesMover() = default;
 
 void CookiesMover::StartMovingCookies() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   bool allow_cookies_to_be_moved = base::FeatureList::IsEnabled(
       profile_management::features::kThirdPartyProfileManagement);
 #else
@@ -402,7 +402,7 @@ bool IsSyncingUserSelectableTypesAllowed
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 bool HasExplicitlyDisabledHistorySync(
     const syncer::SyncService* sync_service,
     const signin::IdentityManager* identity_manager) {
