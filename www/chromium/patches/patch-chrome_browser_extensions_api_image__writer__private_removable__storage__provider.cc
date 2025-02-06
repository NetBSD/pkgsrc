$NetBSD: patch-chrome_browser_extensions_api_image__writer__private_removable__storage__provider.cc,v 1.1 2025/02/06 09:57:47 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/image_writer_private/removable_storage_provider.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/extensions/api/image_writer_private/removable_storage_provider.cc
@@ -20,6 +20,7 @@ static base::LazyInstance<scoped_refptr<
 
 void RemovableStorageProvider::GetAllDevices(DeviceListReadyCallback callback) {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
+#if !BUILDFLAG(IS_BSD)
   if (g_test_device_list.Get().get() != nullptr) {
     base::SingleThreadTaskRunner::GetCurrentDefault()->PostTask(
         FROM_HERE,
@@ -33,6 +34,9 @@ void RemovableStorageProvider::GetAllDev
        base::TaskShutdownBehavior::SKIP_ON_SHUTDOWN},
       base::BindOnce(&RemovableStorageProvider::PopulateDeviceList),
       std::move(callback));
+#else
+  NOTIMPLEMENTED();
+#endif
 }
 
 // static
