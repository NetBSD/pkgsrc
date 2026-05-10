$NetBSD: patch-gpu_config_gpu__control__list.cc,v 1.19 2026/05/10 15:29:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/config/gpu_control_list.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ gpu/config/gpu_control_list.cc
@@ -854,7 +854,7 @@ GpuControlList::OsType GpuControlList::G
   return kOsAndroid;
 #elif BUILDFLAG(IS_FUCHSIA)
   return kOsFuchsia;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kOsLinux;
 #elif BUILDFLAG(IS_MAC)
   return kOsMacosx;
