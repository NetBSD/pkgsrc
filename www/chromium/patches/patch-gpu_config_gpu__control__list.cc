$NetBSD: patch-gpu_config_gpu__control__list.cc,v 1.32 2026/11/08 15:39:05 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/config/gpu_control_list.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ gpu/config/gpu_control_list.cc
@@ -822,7 +822,7 @@ GpuControlList::OsType GpuControlList::G
   return kOsAndroid;
 #elif BUILDFLAG(IS_FUCHSIA)
   return kOsFuchsia;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kOsLinux;
 #elif BUILDFLAG(IS_MAC)
   return kOsMacosx;
