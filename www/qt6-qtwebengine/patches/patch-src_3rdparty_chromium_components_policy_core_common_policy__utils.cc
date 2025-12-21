$NetBSD: patch-src_3rdparty_chromium_components_policy_core_common_policy__utils.cc,v 1.1 2025/12/21 09:38:24 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/policy/core/common/policy_utils.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/components/policy/core/common/policy_utils.cc
@@ -22,7 +22,7 @@ bool IsPolicyTestingEnabled(PrefService*
     return true;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   if (channel == version_info::Channel::DEV) {
     return true;
   }
