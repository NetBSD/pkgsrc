$NetBSD: patch-chrome_test_supervised__user_google__auth__state__waiter__mixin.cc,v 1.19 2026/05/10 15:29:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/test/supervised_user/google_auth_state_waiter_mixin.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/test/supervised_user/google_auth_state_waiter_mixin.cc
@@ -24,7 +24,7 @@ GoogleAuthStateWaiterMixin::GoogleAuthSt
 GoogleAuthStateWaiterMixin::~GoogleAuthStateWaiterMixin() = default;
 
 void GoogleAuthStateWaiterMixin::SetUpOnMainThread() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   ChildAccountService* child_account_service =
       ChildAccountServiceFactory::GetForProfile(
           test_base_->browser()->profile());
