$NetBSD: patch-src_3rdparty_chromium_components_named__mojo__ipc__server_named__mojo__ipc__server__client__util.cc,v 1.1 2025/12/21 09:38:23 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/named_mojo_ipc_server/named_mojo_ipc_server_client_util.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/components/named_mojo_ipc_server/named_mojo_ipc_server_client_util.cc
@@ -23,7 +23,7 @@ namespace named_mojo_ipc_server {
 // static
 mojo::PlatformChannelEndpoint ConnectToServer(
     const mojo::NamedPlatformChannel::ServerName& server_name) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return mojo::NamedPlatformChannel::ConnectToServer(server_name);
 #elif BUILDFLAG(IS_MAC)
   mojo::PlatformChannelEndpoint endpoint =
