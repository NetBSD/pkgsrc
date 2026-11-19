$NetBSD: patch-chrome_test_supervised__user_google__auth__state__waiter__mixin.cc,v 1.33 2026/11/19 19:45:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/test/supervised_user/google_auth_state_waiter_mixin.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/test/supervised_user/google_auth_state_waiter_mixin.cc
@@ -23,7 +23,7 @@ GoogleAuthStateWaiterMixin::GoogleAuthSt
 GoogleAuthStateWaiterMixin::~GoogleAuthStateWaiterMixin() = default;
 
 void GoogleAuthStateWaiterMixin::SetUpOnMainThread() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   ChildAccountService* child_account_service =
       ChildAccountServiceFactory::GetForProfile(
           test_base_->browser()->GetProfile());
