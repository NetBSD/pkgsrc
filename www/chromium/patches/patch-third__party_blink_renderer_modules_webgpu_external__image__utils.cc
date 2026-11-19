$NetBSD: patch-third__party_blink_renderer_modules_webgpu_external__image__utils.cc,v 1.10 2026/11/19 19:46:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/modules/webgpu/external_image_utils.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ third_party/blink/renderer/modules/webgpu/external_image_utils.cc
@@ -424,7 +424,7 @@ bool CopyStaticImageBitmapToWGPUTexture(
 // on linux platform.
 // TODO(crbug.com/1424119): using a webgpu mailbox texture on the OpenGLES
 // backend is failing for unknown reasons.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool forceReadback = true;
 #elif BUILDFLAG(IS_ANDROID)
   // TODO(crbug.com/dawn/1969): Some Android devices don't fail to copy from
