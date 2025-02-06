$NetBSD: patch-chrome_browser_signin_signin__util.cc,v 1.1 2025/02/06 09:57:51 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/signin/signin_util.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/signin/signin_util.cc
@@ -81,7 +81,7 @@ CookiesMover::CookiesMover(base::WeakPtr
 CookiesMover::~CookiesMover() = default;
 
 void CookiesMover::StartMovingCookies() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   bool allow_cookies_to_be_moved = base::FeatureList::IsEnabled(
       profile_management::features::kThirdPartyProfileManagement);
 #else
