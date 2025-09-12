$NetBSD: patch-chrome_utility_services.cc,v 1.7 2025/09/12 16:02:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/utility/services.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ chrome/utility/services.cc
@@ -50,7 +50,7 @@
 #include "chrome/services/system_signals/mac/mac_system_signals_service.h"
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/services/system_signals/linux/linux_system_signals_service.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -215,7 +215,7 @@ auto RunMacNotificationService(
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 auto RunSystemSignalsService(
     mojo::PendingReceiver<device_signals::mojom::SystemSignalsService>
         receiver) {
@@ -490,7 +490,7 @@ void RegisterMainThreadServices(mojo::Se
   services.Add(RunWindowsIconReader);
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   services.Add(RunSystemSignalsService);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
