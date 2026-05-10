$NetBSD: patch-media_gpu_chromeos_gl__image__processor__backend.cc,v 1.19 2026/05/10 15:30:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/chromeos/gl_image_processor_backend.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ media/gpu/chromeos/gl_image_processor_backend.cc
@@ -27,6 +27,10 @@
 #include "ui/ozone/public/ozone_platform.h"
 #include "ui/ozone/public/surface_factory_ozone.h"
 
+#ifndef GL_CONTEXT_LOST_KHR
+#define GL_CONTEXT_LOST_KHR 0x0507
+#endif
+
 namespace media {
 
 namespace {
