$NetBSD: patch-components_password__manager_core_browser_password__store_login__database__async__helper.cc,v 1.31 2026/10/23 15:05:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_store/login_database_async_helper.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ components/password_manager/core/browser/password_store/login_database_async_helper.cc
@@ -143,7 +143,7 @@ LoginDatabaseAsyncHelper::FillMatchingLo
     std::vector<StoredCredential> matched_credentials;
     if (!login_db_ ||
         !login_db_->GetLogins(form, include_psl, &matched_credentials)) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
       return base::unexpected(PasswordStoreBackendError(
           is_encryption_available_
               ? PasswordStoreBackendErrorType::kUncategorized
