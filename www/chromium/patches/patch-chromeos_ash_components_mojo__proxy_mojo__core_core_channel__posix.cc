$NetBSD: patch-chromeos_ash_components_mojo__proxy_mojo__core_core_channel__posix.cc,v 1.4 2026/09/29 07:42:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chromeos/ash/components/mojo_proxy/mojo_core/core/channel_posix.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chromeos/ash/components/mojo_proxy/mojo_core/core/channel_posix.cc
@@ -28,7 +28,7 @@
 #include "build/build_config.h"
 #include "chromeos/ash/components/mojo_proxy/mojo_core/public/cpp/platform/socket_utils_posix.h"
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID))
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD))
 #include "chromeos/ash/components/mojo_proxy/mojo_core/core/channel_linux.h"
 #endif
 
@@ -395,10 +395,11 @@ bool ChannelPosix::WriteNoLock(MessageVi
     if (result < 0) {
       if (errno != EAGAIN &&
           errno != EWOULDBLOCK
-#if BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_NETBSD)
           // On iOS if sendmsg() is trying to send fds between processes and
           // there isn't enough room in the output buffer to send the fd
-          // structure over atomically then EMSGSIZE is returned.
+          // structure over atomically then EMSGSIZE is returned. The same
+          // applies to NetBSD as well.
           //
           // EMSGSIZE presents a problem since the system APIs can only call
           // us when there's room in the socket buffer and not when there is
@@ -574,7 +575,7 @@ scoped_refptr<Channel> Channel::Create(
     ConnectionParams connection_params,
     HandlePolicy handle_policy,
     scoped_refptr<base::SingleThreadTaskRunner> io_task_runner) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return new ChannelLinux(delegate, std::move(connection_params), handle_policy,
                           io_task_runner);
 #else
