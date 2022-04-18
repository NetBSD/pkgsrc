$NetBSD: patch-src_3rdparty_chromium_device_gamepad_gamepad__provider.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/device/gamepad/gamepad_provider.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/device/gamepad/gamepad_provider.cc
@@ -149,7 +149,7 @@ void GamepadProvider::Initialize(std::un
 
   if (!polling_thread_)
     polling_thread_.reset(new base::Thread("Gamepad polling thread"));
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // On Linux, the data fetcher needs to watch file descriptors, so the message
   // loop needs to be a libevent loop.
   const base::MessagePumpType kMessageLoopType = base::MessagePumpType::IO;
