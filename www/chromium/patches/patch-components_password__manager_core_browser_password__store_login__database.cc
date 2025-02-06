$NetBSD: patch-components_password__manager_core_browser_password__store_login__database.cc,v 1.1 2025/02/06 09:58:01 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_store/login_database.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/password_manager/core/browser/password_store/login_database.cc
@@ -1030,7 +1030,7 @@ bool ShouldDeleteUndecryptablePasswords(
     bool is_user_data_dir_policy_set,
     bool is_enabled_by_policy,
     IsAccountStore is_account_store) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string user_data_dir_string;
   std::unique_ptr<base::Environment> environment(base::Environment::Create());
   // On Linux user data directory ca be specified using an env variable. If it
@@ -1049,7 +1049,7 @@ bool ShouldDeleteUndecryptablePasswords(
     return false;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (command_line->HasSwitch(password_manager::kPasswordStore)) {
     RecordShouldDeleteUndecryptablePasswordsMetric(
         ShouldDeleteUndecryptablePasswordsResult::
