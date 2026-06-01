$NetBSD: patch-components_device__signals_core_system__signals_platform__delegate.cc,v 1.20 2026/06/01 10:09:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/system_signals/platform_delegate.cc.orig	2026-05-26 20:39:02.000000000 +0000
+++ components/device_signals/core/system_signals/platform_delegate.cc
@@ -11,7 +11,7 @@ namespace device_signals {
 
 bool CustomFilePathComparator::operator()(const base::FilePath& a,
                                           const base::FilePath& b) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, the file system is case sensitive.
   return a < b;
 #else
