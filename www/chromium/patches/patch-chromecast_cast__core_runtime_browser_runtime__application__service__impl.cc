$NetBSD: patch-chromecast_cast__core_runtime_browser_runtime__application__service__impl.cc,v 1.1 2025/02/06 09:57:58 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chromecast/cast_core/runtime/browser/runtime_application_service_impl.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chromecast/cast_core/runtime/browser/runtime_application_service_impl.cc
@@ -346,7 +346,7 @@ CastWebView::Scoped RuntimeApplicationSe
   params->force_720p_resolution =
       GetFlagEntry(feature::kCastCoreForce720p, config_.extra_features(),
                    /*default_value=*/false);
-#if BUILDFLAG(ENABLE_CAST_RECEIVER) && BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(ENABLE_CAST_RECEIVER) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   // Starboard-based (linux) cast receivers may not render their UI at 720p, so
   // we need to scale to the proper resolution. For example, a 4k TV may render
   // the window at 1920x1080, so a scaling factor of 1.5 is necessary for a 720p
