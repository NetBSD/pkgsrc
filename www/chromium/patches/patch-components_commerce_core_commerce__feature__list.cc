$NetBSD: patch-components_commerce_core_commerce__feature__list.cc,v 1.16 2026/03/14 12:40:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/commerce/core/commerce_feature_list.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ components/commerce/core/commerce_feature_list.cc
@@ -176,7 +176,7 @@ BASE_FEATURE(kShoppingAlternateServer, b
 const char kDiscountOnShoppyPageParam[] = "discount-on-shoppy-page";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD) 
 const base::FeatureParam<bool> kDiscountOnShoppyPage{
     &kEnableDiscountInfoApi, kDiscountOnShoppyPageParam, true};
 #else
@@ -189,7 +189,7 @@ const char kMerchantWideBehaviorParam[] 
 const char kNonMerchantWideBehaviorParam[] = "non-merchant-wide-behavior";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) 
 BASE_FEATURE(kDiscountDialogAutoPopupBehaviorSetting,
              base::FEATURE_ENABLED_BY_DEFAULT);
 const base::FeatureParam<int> kHistoryClustersBehavior{
