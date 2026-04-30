$NetBSD: patch-src_3rdparty_chromium_components_named__mojo__ipc__server_connection__info.h,v 1.2 2026/04/30 06:39:38 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/named_mojo_ipc_server/connection_info.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/named_mojo_ipc_server/connection_info.h
@@ -12,8 +12,16 @@
 #include "base/win/scoped_handle.h"
 #elif BUILDFLAG(IS_MAC)
 #include <bsm/libbsm.h>
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
+#if BUILDFLAG(IS_OPENBSD)
+#include <sys/ucred.h>
+#endif
 #include <sys/socket.h>
+#if defined(__NetBSD__)
+#include <sys/un.h>
+#define ucred unpcbid
+#define SO_PEERCRED LOCAL_PEEREID
+#endif
 #endif
 
 namespace named_mojo_ipc_server {
@@ -29,7 +37,7 @@ struct ConnectionInfo {
   base::ProcessId pid{};
 #if BUILDFLAG(IS_MAC)
   audit_token_t audit_token{};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_BSD)
   ucred credentials{};
 #endif
 };
