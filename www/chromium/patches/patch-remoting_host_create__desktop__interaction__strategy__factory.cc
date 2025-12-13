$NetBSD: patch-remoting_host_create__desktop__interaction__strategy__factory.cc,v 1.8 2025/12/13 14:53:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/create_desktop_interaction_strategy_factory.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ remoting/host/create_desktop_interaction_strategy_factory.cc
@@ -12,7 +12,7 @@
 #include "remoting/host/desktop_interaction_strategy.h"
 #include "remoting/host/legacy_interaction_strategy.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/linux/gnome_interaction_strategy.h"
 #include "third_party/webrtc/modules/desktop_capture/desktop_capturer.h"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -25,7 +25,7 @@ CreateDesktopInteractionStrategyFactory(
     scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner,
     scoped_refptr<base::SingleThreadTaskRunner> video_capture_task_runner,
     scoped_refptr<base::SingleThreadTaskRunner> input_task_runner) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (webrtc::DesktopCapturer::IsRunningUnderWayland()) {
     return std::make_unique<GnomeInteractionStrategyFactory>(ui_task_runner);
   }
