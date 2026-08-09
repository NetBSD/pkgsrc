$NetBSD: patch-gpu_command__buffer_service_shared__image_wrapped__sk__image__backing.cc,v 1.24 2026/08/09 06:31:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/shared_image/wrapped_sk_image_backing.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ gpu/command_buffer/service/shared_image/wrapped_sk_image_backing.cc
@@ -204,7 +204,7 @@ bool WrappedSkImageBacking::Initialize(c
 
     constexpr GrRenderable is_renderable = GrRenderable::kYes;
     constexpr GrProtected is_protected = GrProtected::kNo;
-#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX)
+#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     // Blue for single-planar and magenta-ish for multi-planar.
     SkColor4f fallback_color =
         format().is_single_plane() ? SkColors::kBlue : SkColors::kWhite;
