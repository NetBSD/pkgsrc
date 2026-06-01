$NetBSD: patch-gpu_ipc_service_x__util.h,v 1.20 2026/06/01 10:09:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/ipc/service/x_util.h.orig	2026-05-26 20:39:02.000000000 +0000
+++ gpu/ipc/service/x_util.h
@@ -12,7 +12,7 @@
 #include "gpu/ipc/service/gpu_config.h"
 #include "ui/base/ozone_buildflags.h"
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
 
 namespace gpu {
 
