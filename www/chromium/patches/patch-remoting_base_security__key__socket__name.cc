$NetBSD: patch-remoting_base_security__key__socket__name.cc,v 1.1 2026/05/10 15:30:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/base/security_key_socket_name.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ remoting/base/security_key_socket_name.cc
@@ -25,7 +25,7 @@ base::FilePath GetDefaultSecurityKeySock
   if (!GetSocketNameOverride().empty()) {
     return GetSocketNameOverride();
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // LINT.IfChange(ssh_auth_sock_name)
   const char* xdg_runtime_dir = getenv("XDG_RUNTIME_DIR");
   if (xdg_runtime_dir) {
