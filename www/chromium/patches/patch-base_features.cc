$NetBSD: patch-base_features.cc,v 1.3 2026/08/09 06:31:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/features.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ base/features.cc
@@ -16,7 +16,7 @@
 #include "build/build_config.h"
 #include "build/buildflag.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "base/message_loop/message_pump_epoll.h"
 #endif
 
@@ -240,7 +240,7 @@ void Init() {
   debug::StackTrace::InitializeFeatures();
   FilePath::InitializeFeatures();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   MessagePumpEpoll::InitializeFeatures();
 #endif
 
