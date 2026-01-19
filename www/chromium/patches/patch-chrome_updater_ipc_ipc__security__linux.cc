$NetBSD: patch-chrome_updater_ipc_ipc__security__linux.cc,v 1.3 2026/01/19 16:14:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/updater/ipc/ipc_security_linux.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/updater/ipc/ipc_security_linux.cc
@@ -15,7 +15,11 @@ namespace updater {
 
 bool IsConnectionTrusted(
     const named_mojo_ipc_server::ConnectionInfo& connector) {
+#if BUILDFLAG(IS_NETBSD)
+  return connector.credentials.unp_euid == geteuid();
+#else
   return connector.credentials.uid == geteuid();
+#endif
 }
 
 named_mojo_ipc_server::EndpointOptions CreateServerEndpointOptions(
