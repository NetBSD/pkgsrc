$NetBSD: patch-components_password__manager_core_browser_password__store_login__database__unittest.cc,v 1.14 2026/01/19 16:14:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_store/login_database_unittest.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/password_manager/core/browser/password_store/login_database_unittest.cc
@@ -2227,7 +2227,7 @@ INSTANTIATE_TEST_SUITE_P(MigrationToVCur
                          testing::Values(1, 2, 3, 24));
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 class LoginDatabaseUndecryptableLoginsTest : public testing::Test {
  protected:
   LoginDatabaseUndecryptableLoginsTest() = default;
