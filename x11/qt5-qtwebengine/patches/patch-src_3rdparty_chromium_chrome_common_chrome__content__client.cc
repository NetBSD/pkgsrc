$NetBSD: patch-src_3rdparty_chromium_chrome_common_chrome__content__client.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/chrome/common/chrome_content_client.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/chrome_content_client.cc
@@ -64,7 +64,7 @@
 #include "ui/base/resource/resource_bundle.h"
 #include "url/url_constants.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <fcntl.h>
 #include "chrome/common/component_flash_hint_file_linux.h"
 #include "sandbox/linux/services/credentials.h"
@@ -290,7 +290,7 @@ bool GetComponentUpdatedPepperFlash(cont
 
   return TryCreatePepperFlashInfo(flash_filename, plugin);
 }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 // This method is used on Linux only because of architectural differences in how
 // it loads the component updated flash plugin, and not because the other
 // platforms do not support component updated flash. On other platforms, the
@@ -558,7 +558,7 @@ void ChromeContentClient::AddPepperPlugi
   std::vector<std::unique_ptr<content::PepperPluginInfo>> flash_versions;
 
 // Get component updated flash for desktop Linux and Chrome OS.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Depending on the sandbox configuration, the file system
   // is not always available. If it is not available, do not try and load any
   // flash plugin. The flash player, if any, preloaded before the sandbox
