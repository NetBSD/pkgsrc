$NetBSD: patch-ui_base_dragdrop_os__exchange__data__provider__factory.cc,v 1.18 2026/04/21 15:21:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/dragdrop/os_exchange_data_provider_factory.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ ui/base/dragdrop/os_exchange_data_provider_factory.cc
@@ -7,7 +7,7 @@
 #include "base/notreached.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "ui/base/dragdrop/os_exchange_data_provider_factory_ozone.h"
 #include "ui/base/dragdrop/os_exchange_data_provider_non_backed.h"
 #elif BUILDFLAG(IS_APPLE)
@@ -21,7 +21,7 @@ namespace ui {
 // static
 std::unique_ptr<OSExchangeDataProvider>
 OSExchangeDataProviderFactory::CreateProvider() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The instance can be nullptr in tests that do not instantiate the platform,
   // or on platforms that do not implement specific drag'n'drop.  For them,
   // falling back to the Aura provider should be fine.
