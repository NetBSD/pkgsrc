$NetBSD: patch-src_3rdparty_chromium_components_password__manager_core_browser_password__store_login__database.cc,v 1.2 2026/04/30 06:39:38 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/password_manager/core/browser/password_store/login_database.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/password_manager/core/browser/password_store/login_database.cc
@@ -1036,7 +1036,7 @@ bool ShouldDeleteUndecryptablePasswords(
     bool is_user_data_dir_policy_set,
     bool is_enabled_by_policy,
     IsAccountStore is_account_store) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<base::Environment> environment(base::Environment::Create());
   // On Linux user data directory ca be specified using an env variable. If it
   // exists, passwords shouldn't be deleted.
@@ -1054,7 +1054,7 @@ bool ShouldDeleteUndecryptablePasswords(
     return false;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (command_line->HasSwitch(password_manager::kPasswordStore)) {
     RecordShouldDeleteUndecryptablePasswordsMetric(
         ShouldDeleteUndecryptablePasswordsResult::
