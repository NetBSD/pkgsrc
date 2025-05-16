$NetBSD: patch-chrome_browser_media__galleries_fileapi_mtp__device__map__service.cc,v 1.2 2025/05/16 16:08:17 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media_galleries/fileapi/mtp_device_map_service.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ chrome/browser/media_galleries/fileapi/mtp_device_map_service.cc
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
 
