$NetBSD: patch-components_password__manager_core_browser_password__store_login__database.cc,v 1.25 2026/09/02 13:13:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_store/login_database.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/password_manager/core/browser/password_store/login_database.cc
@@ -1016,7 +1016,7 @@ bool ShouldDeleteUndecryptablePasswords(
     bool is_enabled_by_policy,
     IsAccountStore is_account_store,
     const os_crypt_async::Encryptor* encryptor) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<base::Environment> environment(base::Environment::Create());
   // On Linux user data directory ca be specified using an env variable. If it
   // exists, passwords shouldn't be deleted.
@@ -1030,7 +1030,7 @@ bool ShouldDeleteUndecryptablePasswords(
     return false;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (command_line->HasSwitch(password_manager::kPasswordStore)) {
     return false;
   }
