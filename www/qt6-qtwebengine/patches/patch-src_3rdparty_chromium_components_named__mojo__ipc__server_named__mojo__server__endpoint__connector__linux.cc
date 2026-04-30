$NetBSD: patch-src_3rdparty_chromium_components_named__mojo__ipc__server_named__mojo__server__endpoint__connector__linux.cc,v 1.1 2026/04/30 06:39:38 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/named_mojo_ipc_server/named_mojo_server_endpoint_connector_linux.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/named_mojo_ipc_server/named_mojo_server_endpoint_connector_linux.cc
@@ -89,7 +89,13 @@ void NamedMojoServerEndpointConnectorLin
     PLOG(ERROR) << "getsockopt failed.";
     return;
   }
+#if !BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_NETBSD)
+  info->pid = info->credentials.unp_pid;
+#else
   info->pid = info->credentials.pid;
+#endif
+#endif
 
   mojo::PlatformChannelEndpoint endpoint(
       mojo::PlatformHandle(std::move(connection_fd)));
