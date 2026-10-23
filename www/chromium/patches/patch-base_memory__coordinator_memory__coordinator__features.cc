$NetBSD: patch-base_memory__coordinator_memory__coordinator__features.cc,v 1.1 2026/10/23 15:05:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/memory_coordinator/memory_coordinator_features.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ base/memory_coordinator/memory_coordinator_features.cc
@@ -9,7 +9,7 @@
 namespace base {
 
 BASE_FEATURE(kStatefulMemoryPressure,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
