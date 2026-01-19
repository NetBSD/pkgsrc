$NetBSD: patch-chrome_browser_extensions_api_image__writer__private_removable__storage__provider.cc,v 1.14 2026/01/19 16:14:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/image_writer_private/removable_storage_provider.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/extensions/api/image_writer_private/removable_storage_provider.cc
@@ -9,6 +9,8 @@
 #include "base/task/thread_pool.h"
 #include "content/public/browser/browser_thread.h"
 
+#include "base/notimplemented.h"
+
 namespace extensions {
 
 // A device list to be returned when testing.
@@ -20,6 +22,7 @@ static base::LazyInstance<scoped_refptr<
 
 void RemovableStorageProvider::GetAllDevices(DeviceListReadyCallback callback) {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
+#if !BUILDFLAG(IS_BSD)
   if (g_test_device_list.Get().get() != nullptr) {
     base::SingleThreadTaskRunner::GetCurrentDefault()->PostTask(
         FROM_HERE,
@@ -33,6 +36,9 @@ void RemovableStorageProvider::GetAllDev
        base::TaskShutdownBehavior::SKIP_ON_SHUTDOWN},
       base::BindOnce(&RemovableStorageProvider::PopulateDeviceList),
       std::move(callback));
+#else
+  NOTIMPLEMENTED();
+#endif
 }
 
 // static
