$NetBSD: patch-components_named__mojo__ipc__server_named__mojo__server__endpoint__connector__linux.cc,v 1.5 2025/09/08 13:24:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/named_mojo_ipc_server/named_mojo_server_endpoint_connector_linux.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ components/named_mojo_ipc_server/named_mojo_server_endpoint_connector_linux.cc
@@ -89,7 +89,9 @@ void NamedMojoServerEndpointConnectorLin
     PLOG(ERROR) << "getsockopt failed.";
     return;
   }
+#if !BUILDFLAG(IS_OPENBSD)
   info->pid = info->credentials.pid;
+#endif
 
   mojo::PlatformChannelEndpoint endpoint(
       mojo::PlatformHandle(std::move(connection_fd)));
