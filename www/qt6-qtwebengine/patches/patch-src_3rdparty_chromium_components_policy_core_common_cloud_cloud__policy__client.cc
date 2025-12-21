$NetBSD: patch-src_3rdparty_chromium_components_policy_core_common_cloud_cloud__policy__client.cc,v 1.1 2025/12/21 09:38:24 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/policy/core/common/cloud/cloud_policy_client.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/components/policy/core/common/cloud/cloud_policy_client.cc
@@ -720,7 +720,7 @@ void CloudPolicyClient::FetchPolicy(Poli
         fetch_request->set_invalidation_payload(invalidation_payload_);
       }
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Only set browser device identifier for CBCM Chrome cloud policy on
     // desktop.
     if (type_to_fetch.first ==
