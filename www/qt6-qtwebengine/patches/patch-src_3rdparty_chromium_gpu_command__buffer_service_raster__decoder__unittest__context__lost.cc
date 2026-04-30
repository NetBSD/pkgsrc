$NetBSD: patch-src_3rdparty_chromium_gpu_command__buffer_service_raster__decoder__unittest__context__lost.cc,v 1.1 2026/04/30 06:39:41 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/gpu/command_buffer/service/raster_decoder_unittest_context_lost.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/gpu/command_buffer/service/raster_decoder_unittest_context_lost.cc
@@ -15,6 +15,18 @@ using ::testing::Return;
 using ::testing::SaveArg;
 using ::testing::SetArrayArgument;
 
+#ifndef GL_CONTEXT_LOST_KHR
+#define GL_CONTEXT_LOST_KHR 0x0507
+#endif
+
+#ifndef GL_GUILTY_CONTEXT_RESET_KHR
+#define GL_GUILTY_CONTEXT_RESET_KHR 0x8253
+#endif
+
+#ifndef GL_INNOCENT_CONTEXT_RESET_KHR
+#define GL_INNOCENT_CONTEXT_RESET_KHR 0x8254
+#endif
+
 namespace gpu {
 namespace raster {
 
