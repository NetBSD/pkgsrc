$NetBSD: patch-device_gamepad_gamepad__provider.cc,v 1.27 2026/09/29 07:42:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/gamepad/gamepad_provider.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ device/gamepad/gamepad_provider.cc
@@ -210,7 +210,7 @@ void GamepadProvider::Initialize(std::un
 
   if (!polling_thread_)
     polling_thread_ = std::make_unique<base::Thread>("Gamepad polling thread");
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Linux, the data fetcher needs to watch file descriptors, so the message
   // loop needs to be a libevent loop.
   const base::MessagePumpType kMessageLoopType = base::MessagePumpType::IO;
