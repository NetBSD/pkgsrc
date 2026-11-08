$NetBSD: patch-base_memory__coordinator_memory__coordinator__features.cc,v 1.2 2026/11/08 15:38:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/memory_coordinator/memory_coordinator_features.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ base/memory_coordinator/memory_coordinator_features.cc
@@ -9,7 +9,7 @@
 namespace base {
 
 BASE_FEATURE(kStatefulMemoryPressure,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
