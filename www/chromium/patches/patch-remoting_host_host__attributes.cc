$NetBSD: patch-remoting_host_host__attributes.cc,v 1.29 2026/11/19 19:46:05 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/host_attributes.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ remoting/host/host_attributes.cc
@@ -18,7 +18,7 @@
 #include "remoting/host/win/evaluate_d3d.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/base/username.h"
 #endif
 
@@ -70,7 +70,7 @@ inline constexpr bool IsNonOfficialBuild
 bool IsMultiProcessHost() {
 #if BUILDFLAG(IS_WIN)
   return true;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The Linux host is multi-process only when GetHostAttributes() is called in
   // the network process, which is run as the CRD network user.
   return GetUsername() == GetNetworkProcessUsername();
