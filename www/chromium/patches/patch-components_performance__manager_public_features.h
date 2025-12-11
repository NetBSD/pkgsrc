$NetBSD: patch-components_performance__manager_public_features.h,v 1.11 2025/12/11 09:13:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/performance_manager/public/features.h.orig	2025-11-19 21:40:05.000000000 +0000
+++ components/performance_manager/public/features.h
@@ -19,7 +19,7 @@ namespace performance_manager::features 
 
 #if !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define URGENT_DISCARDING_FROM_PERFORMANCE_MANAGER() false
 #else
 #define URGENT_DISCARDING_FROM_PERFORMANCE_MANAGER() true
