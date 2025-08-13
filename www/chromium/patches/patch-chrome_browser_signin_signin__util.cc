$NetBSD: patch-chrome_browser_signin_signin__util.cc,v 1.5 2025/08/13 07:44:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/signin/signin_util.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ chrome/browser/signin/signin_util.cc
@@ -84,7 +84,7 @@ CookiesMover::CookiesMover(base::WeakPtr
 CookiesMover::~CookiesMover() = default;
 
 void CookiesMover::StartMovingCookies() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   bool allow_cookies_to_be_moved = base::FeatureList::IsEnabled(
       profile_management::features::kThirdPartyProfileManagement);
 #else
@@ -344,7 +344,7 @@ SignedInState GetSignedInState(
   return SignedInState::kSignedOut;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 bool ShouldShowHistorySyncOptinScreen(Profile& profile) {
   if (GetSignedInState(IdentityManagerFactory::GetForProfile(&profile)) !=
       signin_util::SignedInState::kSignedIn) {
