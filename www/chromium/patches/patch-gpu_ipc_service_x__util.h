$NetBSD: patch-gpu_ipc_service_x__util.h,v 1.26 2026/09/22 13:41:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/ipc/service/x_util.h.orig	2026-09-14 22:17:16.000000000 +0000
+++ gpu/ipc/service/x_util.h
@@ -12,7 +12,7 @@
 #include "gpu/ipc/service/gpu_config.h"
 #include "ui/base/ozone_buildflags.h"
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
 
 namespace gpu {
 
