$NetBSD: patch-components_named__mojo__ipc__server_named__mojo__server__endpoint__connector__linux.cc,v 1.14 2026/02/15 09:04:03 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/named_mojo_ipc_server/named_mojo_server_endpoint_connector_linux.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ components/named_mojo_ipc_server/named_mojo_server_endpoint_connector_linux.cc
@@ -7,6 +7,10 @@
 #include <sys/socket.h>
 #include <sys/types.h>
 
+#if BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
+#include <sys/un.h>
+#endif
+
 #include <memory>
 #include <utility>
 
@@ -84,12 +88,24 @@ void NamedMojoServerEndpointConnectorLin
 
   auto info = std::make_unique<ConnectionInfo>();
   socklen_t len = sizeof(info->credentials);
+#if BUILDFLAG(IS_FREEBSD)
+  if (getsockopt(connection_fd.get(), SOL_SOCKET, LOCAL_PEERCRED,
+#elif BUILDFLAG(IS_NETBSD)
+  if (getsockopt(connection_fd.get(), 0, LOCAL_PEEREID,
+#else
   if (getsockopt(connection_fd.get(), SOL_SOCKET, SO_PEERCRED,
+#endif
                  &info->credentials, &len) != 0) {
     PLOG(ERROR) << "getsockopt failed.";
     return;
   }
+#if BUILDFLAG(IS_FREEBSD)
+  info->pid = info->credentials.cr_pid;
+#elif BUILDFLAG(IS_NETBSD)
+  info->pid = info->credentials.unp_pid;
+#elif !BUILDFLAG(IS_OPENBSD)
   info->pid = info->credentials.pid;
+#endif
 
   mojo::PlatformChannelEndpoint endpoint(
       mojo::PlatformHandle(std::move(connection_fd)));
