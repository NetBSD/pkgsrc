$NetBSD: patch-media_gpu_chromeos_gl__image__processor__backend.cc,v 1.14 2026/01/19 16:14:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/chromeos/gl_image_processor_backend.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ media/gpu/chromeos/gl_image_processor_backend.cc
@@ -28,6 +28,10 @@
 #include "ui/ozone/public/ozone_platform.h"
 #include "ui/ozone/public/surface_factory_ozone.h"
 
+#ifndef GL_CONTEXT_LOST_KHR
+#define GL_CONTEXT_LOST_KHR 0x0507
+#endif
+
 namespace media {
 
 namespace {
