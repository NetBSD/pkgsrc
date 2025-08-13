$NetBSD: patch-chrome_browser_signin_signin__util.h,v 1.1 2025/08/13 07:44:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/signin/signin_util.h.orig	2025-07-29 22:51:44.000000000 +0000
+++ chrome/browser/signin/signin_util.h
@@ -168,7 +168,7 @@ bool IsSigninPending(signin::IdentityMan
 // Returns the current state of the primary account that is used in Chrome.
 SignedInState GetSignedInState(const signin::IdentityManager* identity_manager);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Returns if the necessary conditions to show the History Sync Optin screen
 // are met.
 // This method does not take into account any feature flags related to the above
