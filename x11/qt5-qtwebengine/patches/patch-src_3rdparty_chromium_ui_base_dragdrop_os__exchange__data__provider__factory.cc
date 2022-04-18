$NetBSD: patch-src_3rdparty_chromium_ui_base_dragdrop_os__exchange__data__provider__factory.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/base/dragdrop/os_exchange_data_provider_factory.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/base/dragdrop/os_exchange_data_provider_factory.cc
@@ -7,7 +7,7 @@
 #include "base/notreached.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/base/dragdrop/os_exchange_data_provider_non_backed.h"
 #include "ui/base/ui_base_features.h"
 #if defined(USE_OZONE)
@@ -26,7 +26,7 @@ namespace ui {
 
 namespace {
 
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(TOOLKIT_QT)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && !defined(TOOLKIT_QT)
 std::unique_ptr<OSExchangeDataProvider> CreateProviderForLinux() {
 #if defined(USE_OZONE)
   // The instance can be nullptr in tests that do not instantiate the platform,
@@ -51,7 +51,7 @@ std::unique_ptr<OSExchangeDataProvider> 
 // static
 std::unique_ptr<OSExchangeDataProvider>
 OSExchangeDataProviderFactory::CreateProvider() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (features::IsUsingOzonePlatform())
     return CreateProviderForLinux();
 #if defined(USE_X11)
