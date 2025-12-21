$NetBSD: patch-src_3rdparty_chromium_components_device__signals_core_browser_user__permission__service__impl.cc,v 1.1 2025/12/21 09:38:21 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/device_signals/core/browser/user_permission_service_impl.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/components/device_signals/core/browser/user_permission_service_impl.cc
@@ -87,7 +87,7 @@ bool UserPermissionServiceImpl::ShouldCo
          consent_required_by_dependent_policy;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 UserPermission UserPermissionServiceImpl::CanUserCollectSignals(
     const UserContext& user_context) const {
   // Return "unknown user" if no user ID was given.
