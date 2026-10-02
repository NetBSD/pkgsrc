$NetBSD: patch-chrome_browser_signin_signin__util.cc,v 1.28 2026/10/02 11:43:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/signin/signin_util.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/signin/signin_util.cc
@@ -43,7 +43,7 @@
 #include "google_apis/gaia/gaia_id.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/dialogs/browser_dialogs.h"
 #include "components/strings/grit/components_strings.h"
 #include "ui/base/interaction/element_identifier.h"
@@ -325,7 +325,7 @@ bool IsSyncingUserSelectableTypesAllowed
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 bool HasExplicitlyDisabledHistorySync(
     const syncer::SyncService* sync_service,
     const signin::IdentityManager* identity_manager) {
