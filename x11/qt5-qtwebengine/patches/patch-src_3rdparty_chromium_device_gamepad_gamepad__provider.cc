$NetBSD: patch-src_3rdparty_chromium_device_gamepad_gamepad__provider.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/device/gamepad/gamepad_provider.cc.orig	2020-07-08 21:40:43.000000000 +0000
+++ src/3rdparty/chromium/device/gamepad/gamepad_provider.cc
@@ -147,7 +147,7 @@ void GamepadProvider::Initialize(std::un
 
   if (!polling_thread_)
     polling_thread_.reset(new base::Thread("Gamepad polling thread"));
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, the data fetcher needs to watch file descriptors, so the message
   // loop needs to be a libevent loop.
   const base::MessagePumpType kMessageLoopType = base::MessagePumpType::IO;
