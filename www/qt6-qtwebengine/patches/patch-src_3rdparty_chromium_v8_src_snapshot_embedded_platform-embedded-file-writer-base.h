$NetBSD: patch-src_3rdparty_chromium_v8_src_snapshot_embedded_platform-embedded-file-writer-base.h,v 1.2 2026/04/30 06:39:46 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/v8/src/snapshot/embedded/platform-embedded-file-writer-base.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/v8/src/snapshot/embedded/platform-embedded-file-writer-base.h
@@ -36,6 +36,7 @@ enum class EmbeddedTargetOs {
   kWin,
   kStarboard,
   kZOS,
+  kOpenBSD,
   kGeneric,  // Everything not covered above falls in here.
 };
 
