$NetBSD: patch-components_device__signals_core_browser_user__permission__service__impl.h,v 1.23 2026/07/08 13:42:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/browser/user_permission_service_impl.h.orig	2026-07-06 22:58:46.000000000 +0000
+++ components/device_signals/core/browser/user_permission_service_impl.h
@@ -38,7 +38,7 @@ class UserPermissionServiceImpl : public
 
   // UserPermissionService:
   bool ShouldCollectConsent() const override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   UserPermission CanUserCollectSignals(
       const UserContext& user_context) const override;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX
