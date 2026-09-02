$NetBSD: patch-chromeos_ash_components_mojo__proxy_mojo__core_core_channel__posix.cc,v 1.2 2026/09/02 13:13:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chromeos/ash/components/mojo_proxy/mojo_core/core/channel_posix.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chromeos/ash/components/mojo_proxy/mojo_core/core/channel_posix.cc
@@ -28,7 +28,7 @@
 #include "build/build_config.h"
 #include "chromeos/ash/components/mojo_proxy/mojo_core/public/cpp/platform/socket_utils_posix.h"
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID))
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD))
 #include "chromeos/ash/components/mojo_proxy/mojo_core/core/channel_linux.h"
 #endif
 
@@ -574,7 +574,7 @@ scoped_refptr<Channel> Channel::Create(
     ConnectionParams connection_params,
     HandlePolicy handle_policy,
     scoped_refptr<base::SingleThreadTaskRunner> io_task_runner) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return new ChannelLinux(delegate, std::move(connection_params), handle_policy,
                           io_task_runner);
 #else
