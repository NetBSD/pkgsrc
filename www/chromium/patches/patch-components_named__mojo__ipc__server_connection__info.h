$NetBSD: patch-components_named__mojo__ipc__server_connection__info.h,v 1.24 2026/08/09 06:31:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/named_mojo_ipc_server/connection_info.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ components/named_mojo_ipc_server/connection_info.h
@@ -15,7 +15,12 @@
 #include "base/win/scoped_handle.h"
 #elif BUILDFLAG(IS_MAC)
 #include <bsm/libbsm.h>
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
+#if BUILDFLAG(IS_NETBSD)
+#include <sys/un.h>
+#else
+#include <sys/ucred.h>
+#endif
 #include <sys/socket.h>
 #endif
 
@@ -32,8 +37,12 @@ struct ConnectionInfo {
   base::ProcessId pid{};
 #if BUILDFLAG(IS_MAC)
   audit_token_t audit_token{};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
   ucred credentials{};
+#elif BUILDFLAG(IS_FREEBSD)
+  xucred credentials{};
+#elif BUILDFLAG(IS_NETBSD)
+  unpcbid credentials{};
 #elif BUILDFLAG(IS_WIN)
   // The process of the peer. Only valid if `include_peer_process_info` is true
   // in EndpointOptions.
