$NetBSD: patch-components_policy_core_common_cloud_cloud__policy__client.cc,v 1.14 2026/01/19 16:14:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/policy/core/common/cloud/cloud_policy_client.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/policy/core/common/cloud/cloud_policy_client.cc
@@ -779,7 +779,7 @@ void CloudPolicyClient::FetchPolicy(Poli
         fetch_request->set_invalidation_payload(invalidation_payload_);
       }
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Only set browser device identifier for CBCM Chrome cloud policy on
     // desktop.
     if (type_to_fetch.policy_type() ==
