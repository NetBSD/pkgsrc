$NetBSD: patch-components_device__signals_core_browser_user__permission__service__impl.h,v 1.19 2026/05/10 15:29:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/browser/user_permission_service_impl.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/device_signals/core/browser/user_permission_service_impl.h
@@ -38,7 +38,7 @@ class UserPermissionServiceImpl : public
 
   // UserPermissionService:
   bool ShouldCollectConsent() const override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   UserPermission CanUserCollectSignals(
       const UserContext& user_context) const override;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX
