$NetBSD: patch-src_3rdparty_chromium_device_gamepad_gamepad__provider.cc,v 1.1 2025/12/21 09:38:29 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/device/gamepad/gamepad_provider.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/device/gamepad/gamepad_provider.cc
@@ -224,7 +224,7 @@ void GamepadProvider::Initialize(std::un
 
   if (!polling_thread_)
     polling_thread_ = std::make_unique<base::Thread>("Gamepad polling thread");
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Linux, the data fetcher needs to watch file descriptors, so the message
   // loop needs to be a libevent loop.
   const base::MessagePumpType kMessageLoopType = base::MessagePumpType::IO;
