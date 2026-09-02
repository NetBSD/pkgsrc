$NetBSD: patch-remoting_base_security__key__socket__name.cc,v 1.7 2026/09/02 13:13:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/base/security_key_socket_name.cc.orig	2026-08-31 22:47:51.000000000 +0000
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
