$NetBSD: patch-src_3rdparty_chromium_chrome_browser_signin_accounts__policy__manager.h,v 1.1 2026/04/30 06:39:36 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/signin/accounts_policy_manager.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/signin/accounts_policy_manager.h
@@ -13,7 +13,7 @@
 #include "components/signin/public/base/signin_metrics.h"
 #include "components/signin/public/identity_manager/identity_manager.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/scoped_observation.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -64,7 +64,7 @@ class AccountsPolicyManager : public Key
   }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void RemoveUnallowedAccounts();
 
   // IdentityManager::Observer implementation.
@@ -85,7 +85,7 @@ class AccountsPolicyManager : public Key
   bool hide_ui_for_testing_ = false;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedObservation<signin::IdentityManager,
                           signin::IdentityManager::Observer>
       identity_manager_observation_{this};
