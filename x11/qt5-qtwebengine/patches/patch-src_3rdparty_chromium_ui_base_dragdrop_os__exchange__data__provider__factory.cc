$NetBSD: patch-src_3rdparty_chromium_ui_base_dragdrop_os__exchange__data__provider__factory.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/base/dragdrop/os_exchange_data_provider_factory.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/ui/base/dragdrop/os_exchange_data_provider_factory.cc
@@ -8,7 +8,7 @@
 
 #if defined(USE_X11)
 #include "ui/base/dragdrop/os_exchange_data_provider_aurax11.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/base/dragdrop/os_exchange_data_provider_aura.h"
 #elif defined(OS_MACOSX)
 #include "ui/base/dragdrop/os_exchange_data_provider_builder_mac.h"
@@ -24,7 +24,7 @@ std::unique_ptr<OSExchangeData::Provider
 OSExchangeDataProviderFactory::CreateProvider() {
 #if defined(USE_X11)
   return std::make_unique<OSExchangeDataProviderAuraX11>();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return std::make_unique<OSExchangeDataProviderAura>();
 #elif defined(OS_MACOSX)
   return ui::BuildOSExchangeDataProviderMac();
