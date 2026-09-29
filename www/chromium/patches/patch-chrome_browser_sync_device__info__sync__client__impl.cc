$NetBSD: patch-chrome_browser_sync_device__info__sync__client__impl.cc,v 1.27 2026/09/29 07:42:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/sync/device_info_sync_client_impl.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/sync/device_info_sync_client_impl.cc
@@ -41,7 +41,7 @@ DeviceInfoSyncClientImpl::~DeviceInfoSyn
 std::string DeviceInfoSyncClientImpl::GetSigninScopedDeviceId() const {
 // Since the local sync backend is currently only supported on Windows, Mac and
 // Linux don't even check the pref on other os-es.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   syncer::SyncPrefs prefs(profile_->GetPrefs());
   if (prefs.IsLocalSyncEnabled()) {
     return "local_device";
