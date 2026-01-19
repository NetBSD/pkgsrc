$NetBSD: patch-device_gamepad_gamepad__provider.cc,v 1.14 2026/01/19 16:14:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/gamepad/gamepad_provider.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ device/gamepad/gamepad_provider.cc
@@ -201,7 +201,7 @@ void GamepadProvider::Initialize(std::un
 
   if (!polling_thread_)
     polling_thread_ = std::make_unique<base::Thread>("Gamepad polling thread");
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Linux, the data fetcher needs to watch file descriptors, so the message
   // loop needs to be a libevent loop.
   const base::MessagePumpType kMessageLoopType = base::MessagePumpType::IO;
