$NetBSD: patch-remoting_host_client__session.cc,v 1.11 2025/12/11 09:13:41 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/client_session.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ remoting/host/client_session.cc
@@ -195,7 +195,7 @@ void ClientSession::NotifyClientResoluti
   if (effective_policies_.curtain_required.value_or(false)) {
     dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
 #endif
 
