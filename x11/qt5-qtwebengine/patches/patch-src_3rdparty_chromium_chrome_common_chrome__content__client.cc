$NetBSD: patch-src_3rdparty_chromium_chrome_common_chrome__content__client.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/chrome/common/chrome_content_client.cc.orig	2020-07-08 21:41:47.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/chrome_content_client.cc
@@ -65,7 +65,7 @@
 #include "ui/base/resource/resource_bundle.h"
 #include "url/url_constants.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <fcntl.h>
 #include "chrome/common/component_flash_hint_file_linux.h"
 #include "sandbox/linux/services/credentials.h"
@@ -294,7 +294,7 @@ bool GetComponentUpdatedPepperFlash(cont
 
   return TryCreatePepperFlashInfo(flash_filename, plugin);
 }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 // This method is used on Linux only because of architectural differences in how
 // it loads the component updated flash plugin, and not because the other
 // platforms do not support component updated flash. On other platforms, the
@@ -557,7 +557,7 @@ void ChromeContentClient::AddPepperPlugi
   std::vector<std::unique_ptr<content::PepperPluginInfo>> flash_versions;
 
 // Get component updated flash for desktop Linux and Chrome OS.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Depending on the sandbox configuration, the file system
   // is not always available. If it is not available, do not try and load any
   // flash plugin. The flash player, if any, preloaded before the sandbox
