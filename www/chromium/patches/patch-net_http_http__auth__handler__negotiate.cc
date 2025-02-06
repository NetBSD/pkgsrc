$NetBSD: patch-net_http_http__auth__handler__negotiate.cc,v 1.1 2025/02/06 09:58:15 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/http/http_auth_handler_negotiate.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ net/http/http_auth_handler_negotiate.cc
@@ -120,7 +120,7 @@ int HttpAuthHandlerNegotiate::Factory::C
 #elif BUILDFLAG(IS_POSIX)
   if (is_unsupported_)
     return ERR_UNSUPPORTED_AUTH_SCHEME;
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Note: Don't set is_unsupported_ = true here. AllowGssapiLibraryLoad()
   // might change to true during a session.
   if (!http_auth_preferences() ||
