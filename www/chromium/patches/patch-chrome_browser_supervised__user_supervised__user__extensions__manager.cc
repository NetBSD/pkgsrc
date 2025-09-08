$NetBSD: patch-chrome_browser_supervised__user_supervised__user__extensions__manager.cc,v 1.6 2025/09/08 13:24:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/supervised_user/supervised_user_extensions_manager.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/browser/supervised_user/supervised_user_extensions_manager.cc
@@ -350,7 +350,7 @@ void SupervisedUserExtensionsManager::
     ActivateManagementPolicyAndUpdateRegistration() {
   SetActiveForSupervisedUsers();
   UpdateManagementPolicyRegistration();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   MaybeMarkExtensionsLocallyParentApproved();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 }
@@ -449,7 +449,7 @@ bool SupervisedUserExtensionsManager::Sh
   return false;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SupervisedUserExtensionsManager::
     MaybeMarkExtensionsLocallyParentApproved() {
   supervised_user::LocallyParentApprovedExtensionsMigrationState
