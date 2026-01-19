$NetBSD: patch-services_screen__ai_screen__ai__service__impl.cc,v 1.10 2026/01/19 16:14:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/screen_ai/screen_ai_service_impl.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ services/screen_ai/screen_ai_service_impl.cc
@@ -34,7 +34,7 @@
 #include "ui/accessibility/ax_tree_id.h"
 #include "ui/gfx/geometry/rect_f.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "partition_alloc/buildflags.h"
 
 #if PA_BUILDFLAG( \
@@ -240,7 +240,7 @@ ScreenAIService::ScreenAIService(
     : factory_receiver_(this, std::move(receiver)),
       ocr_receiver_(this),
       main_content_extraction_receiver_(this) {
-#if BUILDFLAG(IS_LINUX) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && \
     PA_BUILDFLAG(          \
         ENABLE_ALLOCATOR_SHIM_PARTITION_ALLOC_DISPATCH_WITH_ADVANCED_CHECKS_SUPPORT)
   // TODO(crbug.com/418199684): Remove when the bug is fixed.
