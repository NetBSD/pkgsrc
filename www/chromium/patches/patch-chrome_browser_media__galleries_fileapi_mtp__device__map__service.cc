$NetBSD: patch-chrome_browser_media__galleries_fileapi_mtp__device__map__service.cc,v 1.14 2026/01/19 16:14:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media_galleries/fileapi/mtp_device_map_service.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/media_galleries/fileapi/mtp_device_map_service.cc
@@ -30,7 +30,7 @@ void MTPDeviceMapService::RegisterMTPFil
     const base::FilePath::StringType& device_location,
     const std::string& filesystem_id,
     const bool read_only) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DCHECK_CURRENTLY_ON(content::BrowserThread::IO);
   DCHECK(!device_location.empty());
   DCHECK(!filesystem_id.empty());
@@ -40,10 +40,12 @@ void MTPDeviceMapService::RegisterMTPFil
     // Note that this initializes the delegate asynchronously, but since
     // the delegate will only be used from the IO thread, it is guaranteed
     // to be created before use of it expects it to be there.
+#if !BUILDFLAG(IS_BSD) 
     CreateMTPDeviceAsyncDelegate(
         device_location, read_only,
         base::BindOnce(&MTPDeviceMapService::AddAsyncDelegate,
                        base::Unretained(this), device_location, read_only));
+#endif
     mtp_device_usage_map_[key] = 0;
   }
 
