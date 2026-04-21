$NetBSD: patch-components_policy_core_common_cloud_cloud__policy__client.cc,v 1.18 2026/04/21 15:21:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/policy/core/common/cloud/cloud_policy_client.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ components/policy/core/common/cloud/cloud_policy_client.cc
@@ -849,11 +849,11 @@ void CloudPolicyClient::FetchPolicyInter
 
   // Build policy fetch requests.
   em::DevicePolicyRequest* policy_request = request->mutable_policy_request();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   em::PolicyFetchRequest* fetch_request = nullptr;
 #endif
   for (const auto& type_to_fetch : types_to_fetch) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     fetch_request = AddPolicyFetchRequest(policy_request, type_to_fetch);
     // Only set browser device identifier for CBCM Chrome cloud policy on
     // desktop.
