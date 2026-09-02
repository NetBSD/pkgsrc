$NetBSD: patch-net_socket_extra__socket__defines.h,v 1.1 2026/09/02 13:13:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/socket/extra_socket_defines.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ net/socket/extra_socket_defines.h
@@ -7,7 +7,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include <netinet/in.h>
 #include <sys/socket.h>
 
