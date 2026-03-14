$NetBSD: patch-components_named__mojo__ipc__server_named__mojo__server__endpoint__connector__linux.cc,v 1.15 2026/03/14 12:40:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/named_mojo_ipc_server/named_mojo_server_endpoint_connector_linux.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ components/named_mojo_ipc_server/named_mojo_server_endpoint_connector_linux.cc
@@ -8,6 +8,10 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 
+#if BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
+#include <sys/un.h>
+#endif
+
 #include <memory>
 #include <utility>
 
@@ -86,12 +90,24 @@ void NamedMojoServerEndpointConnectorLin
 
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
@@ -116,7 +132,7 @@ bool NamedMojoServerEndpointConnectorLin
   if (!options_.require_same_peer_user) {
     // Allow any user to write to the UDS. fchmod doesn't work after bind(), so
     // we need to call chmod on the socket filename, which is the server name.
-    if (chmod(options_.server_name.c_str(), 0o666) != 0) {
+    if (chmod(options_.server_name.c_str(), 0666) != 0) {
       PLOG(ERROR) << "chmod failed";
       return false;
     }
