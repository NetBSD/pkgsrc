$NetBSD: patch-remoting_host_desktop__and__cursor__conditional__composer.cc,v 1.1 2025/02/06 09:58:17 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/desktop_and_cursor_conditional_composer.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ remoting/host/desktop_and_cursor_conditional_composer.cc
@@ -7,7 +7,7 @@
 #include "base/functional/bind.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/linux/wayland_utils.h"
 #endif
 
@@ -96,7 +96,7 @@ bool DesktopAndCursorConditionalComposer
 }
 
 bool DesktopAndCursorConditionalComposer::SupportsFrameCallbacks() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return IsRunningWayland();
 #else
   return false;
