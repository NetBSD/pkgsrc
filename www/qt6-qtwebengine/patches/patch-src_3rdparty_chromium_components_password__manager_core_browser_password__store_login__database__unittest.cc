$NetBSD: patch-src_3rdparty_chromium_components_password__manager_core_browser_password__store_login__database__unittest.cc,v 1.1 2025/12/21 09:38:24 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/password_manager/core/browser/password_store/login_database_unittest.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/components/password_manager/core/browser/password_store/login_database_unittest.cc
@@ -2253,7 +2253,7 @@ INSTANTIATE_TEST_SUITE_P(MigrationToVCur
                                           testing::Bool()));
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 class LoginDatabaseUndecryptableLoginsTest : public testing::Test {
  protected:
   LoginDatabaseUndecryptableLoginsTest() = default;
