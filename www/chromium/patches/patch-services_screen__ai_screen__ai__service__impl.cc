$NetBSD: patch-services_screen__ai_screen__ai__service__impl.cc,v 1.20 2026/08/09 06:31:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/screen_ai/screen_ai_service_impl.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ services/screen_ai/screen_ai_service_impl.cc
@@ -32,7 +32,7 @@
 #include "ui/accessibility/ax_tree_id.h"
 #include "ui/gfx/geometry/rect_f.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "partition_alloc/buildflags.h"
 
 #if PA_BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
@@ -209,7 +209,7 @@ ScreenAIService::ScreenAIService(
     : factory_receiver_(this, std::move(receiver)),
       ocr_receiver_(this),
       main_content_extraction_receiver_(this) {
-#if BUILDFLAG(IS_LINUX) && PA_BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && PA_BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
   // TODO(crbug.com/418199684): Remove when the bug is fixed.
   if (base::FeatureList::IsEnabled(
           ::features::kScreenAIPartitionAllocAdvancedChecksEnabled)) {
