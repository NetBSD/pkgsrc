$NetBSD: patch-gpu_ipc_service_x__util.h,v 1.15 2026/02/15 09:04:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/ipc/service/x_util.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ gpu/ipc/service/x_util.h
@@ -12,7 +12,7 @@
 #include "gpu/ipc/service/gpu_config.h"
 #include "ui/base/ozone_buildflags.h"
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
 
 namespace gpu {
 
