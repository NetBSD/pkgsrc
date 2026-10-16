$NetBSD: patch-components_named__mojo__ipc__server_endpoint__options.h,v 1.15 2026/10/16 15:30:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/named_mojo_ipc_server/endpoint_options.h.orig	2026-10-14 21:09:54.000000000 +0000
+++ components/named_mojo_ipc_server/endpoint_options.h
@@ -77,7 +77,7 @@ struct EndpointOptions {
   std::wstring security_descriptor;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Iff this is true, connecting clients running as a different user from the
   // server (i.e. the calling process) will be rejected.
   bool require_same_peer_user = true;
