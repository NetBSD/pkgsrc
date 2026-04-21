$NetBSD: patch-components_password__manager_core_browser_password__store_login__database__unittest.cc,v 1.18 2026/04/21 15:21:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_store/login_database_unittest.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ components/password_manager/core/browser/password_store/login_database_unittest.cc
@@ -2230,7 +2230,7 @@ INSTANTIATE_TEST_SUITE_P(MigrationToVCur
                          testing::Values(1, 2, 3, 24));
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 class LoginDatabaseUndecryptableLoginsTest : public testing::Test {
  protected:
   LoginDatabaseUndecryptableLoginsTest() = default;
