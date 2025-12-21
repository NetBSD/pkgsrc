$NetBSD: patch-src_3rdparty_chromium_gpu_command__buffer_service_shared__image_wrapped__sk__image__backing.cc,v 1.1 2025/12/21 09:38:30 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/gpu/command_buffer/service/shared_image/wrapped_sk_image_backing.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/gpu/command_buffer/service/shared_image/wrapped_sk_image_backing.cc
@@ -214,7 +214,7 @@ bool WrappedSkImageBacking::Initialize(c
 
     constexpr GrRenderable is_renderable = GrRenderable::kYes;
     constexpr GrProtected is_protected = GrProtected::kNo;
-#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX)
+#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     // Blue for single-planar and magenta-ish for multi-planar.
     SkColor4f fallback_color =
         format().is_single_plane() ? SkColors::kBlue : SkColors::kWhite;
