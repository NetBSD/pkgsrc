$NetBSD: patch-chrome_updater_ipc_ipc__security__linux.cc,v 1.14 2026/09/02 13:13:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/updater/ipc/ipc_security_linux.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/updater/ipc/ipc_security_linux.cc
@@ -16,7 +16,11 @@ namespace updater {
 
 bool IsConnectionTrusted(
     const named_mojo_ipc_server::ConnectionInfo& connector) {
+#if BUILDFLAG(IS_NETBSD)
+  return connector.credentials.unp_euid == geteuid();
+#else
   return connector.credentials.uid == geteuid();
+#endif
 }
 
 named_mojo_ipc_server::EndpointOptions CreateServerEndpointOptions(
