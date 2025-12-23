$NetBSD: patch-chrome_enterprise__companion_ipc__security__linux.cc,v 1.2 2025/12/23 13:22:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/enterprise_companion/ipc_security_linux.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ chrome/enterprise_companion/ipc_security_linux.cc
@@ -15,7 +15,11 @@ namespace enterprise_companion {
 IpcTrustDecider CreateIpcTrustDecider() {
   return base::BindRepeating(
       [](const named_mojo_ipc_server::ConnectionInfo& connector) {
+#if BUILDFLAG(IS_NETBSD)
+        return connector.credentials.unp_euid == geteuid();
+#else
         return connector.credentials.uid == geteuid();
+#endif
       });
 }
 
